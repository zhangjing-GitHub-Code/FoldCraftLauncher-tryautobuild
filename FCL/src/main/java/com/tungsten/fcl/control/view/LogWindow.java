package com.tungsten.fcl.control.view;

import android.content.Context;
import android.graphics.Color;
import android.util.AttributeSet;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ScrollView;
import android.widget.TextView;

import com.tungsten.fclcore.fakefx.beans.property.BooleanProperty;
import com.tungsten.fclcore.fakefx.beans.property.BooleanPropertyBase;
import com.tungsten.fclcore.task.Schedulers;

public class LogWindow extends ScrollView {

    private BooleanProperty visibilityProperty;
    private TextView textView;
    private int lineCount;

    public LogWindow(Context context) {
        super(context);
        init(context);
    }

    public LogWindow(Context context, AttributeSet attrs) {
        super(context, attrs);
        init(context);
    }

    public LogWindow(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        init(context);
    }

    public LogWindow(Context context, AttributeSet attrs, int defStyleAttr, int defStyleRes) {
        super(context, attrs, defStyleAttr, defStyleRes);
        init(context);
    }

    private void init(Context context) {
        this.textView = new TextView(context);
        textView.setLayoutParams(new ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT));
        addView(textView);
        textView.setTextColor(Color.WHITE);
        textView.setTextIsSelectable(true);
        textView.setTextSize(15);
        textView.setLineSpacing(0, 1f);
    }

    public final void setVisibilityValue(boolean visibility) {
        visibilityProperty().set(visibility);
    }

    public final boolean getVisibilityValue() {
        return visibilityProperty == null || visibilityProperty.get();
    }

    public final BooleanProperty visibilityProperty() {
        if (visibilityProperty == null) {
            visibilityProperty = new BooleanPropertyBase() {

                @Override
                public void invalidated() {
                    Schedulers.androidUIThread().execute(() -> {
                        boolean visible = get();
                        setVisibility(visible ? VISIBLE : GONE);
                        if (!visible) {
                            cleanLog();
                        }
                    });
                }

                @Override
                public Object getBean() {
                    return this;
                }

                @Override
                public String getName() {
                    return "visibility";
                }
            };
        }

        return visibilityProperty;
    }

    public void appendLog(String str) {
        if (!getVisibilityValue()) {
            return;
        }
        lineCount++;
        this.post(() -> {
            if (textView != null) {
                if (lineCount < 100) {
                    textView.append(str);
                } else {
                    cleanLog();
                }
                postDelayed(() -> toBottom(LogWindow.this, textView), 50);
            }
        });
    }

    public void cleanLog() {
        this.textView.setText("");
        lineCount = 0;
    }

    private void toBottom(ScrollView scrollView, View view) {
        int offset = view.getHeight()
                - scrollView.getHeight();
        if (offset < 0) {
            offset = 0;
        }
        scrollView.scrollTo(0, offset);
    }
}
