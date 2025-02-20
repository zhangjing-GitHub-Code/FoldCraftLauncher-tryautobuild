/* 
 * Copyright (c) 2002-2008 LWJGL Project
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are 
 * met:
 * 
 * * Redistributions of source code must retain the above copyright 
 *   notice, this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * * Neither the name of 'LWJGL' nor the names of 
 *   its contributors may be used to endorse or promote products derived 
 *   from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR 
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 *
 * FCL mouse handling.
 *
 * @author Tungsten
 */

#include <fcl_bridge.h>
#include "common_tools.h"
#include "org_lwjgl_opengl_FCLMouse.h"

JNIEXPORT jint JNICALL Java_org_lwjgl_opengl_FCLMouse_nGetWindowHeight(JNIEnv *env, jclass unused, jlong window_ptr) {
	ANativeWindow *win = (ANativeWindow *)(intptr_t)window_ptr;
	return ANativeWindow_getHeight(win);
}

JNIEXPORT jint JNICALL Java_org_lwjgl_opengl_FCLMouse_nGetWindowWidth(JNIEnv *env, jclass unused, jlong window_ptr) {
	ANativeWindow *win = (ANativeWindow *)(intptr_t)window_ptr;
	return ANativeWindow_getWidth(win);
}

JNIEXPORT jint JNICALL Java_org_lwjgl_opengl_FCLMouse_nGetButtonCount(JNIEnv *env, jclass unused) {
	int count = 16;

	return count;
}
