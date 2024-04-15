package com.cucumbers.boxinput;

import android.app.Activity;
import android.os.Bundle;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.content.Context;
import android.view.Window;
import android.view.WindowManager;

public class MainActivity extends Activity {

    private MyVulkanSurface surface;

    public static native void launchApp();
    public static native void destroyApp();

    @Override
    protected void onCreate(Bundle bundle) {
        super.onCreate(bundle);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);

        loadLibs();

        surface = new MyVulkanSurface(this);

        setContentView(surface);
    }

    @Override
    protected void onStart() {
        super.onStart();

        launchApp();
    }

    @Override
    protected void onDestroy() {
        destroyApp();

        super.onDestroy();
    }

    protected void loadLibs() {
        System.loadLibrary("BoxInput");
    }
}

class MyVulkanSurface extends SurfaceView implements SurfaceHolder.Callback {

    public static native void initWindow(Surface surface);
    public static native void destroyWindow();

    public MyVulkanSurface(Context context) {
        super(context);

        setFocusable(true);
        setFocusableInTouchMode(true);
        requestFocus();
    }

    public Surface getSurface() {
        return getHolder().getSurface();
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        initWindow(holder.getSurface());
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        destroyWindow();
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
        // since orientation is locked, i think we can ignore this (too lazy to implement surface changes)
    }
}
