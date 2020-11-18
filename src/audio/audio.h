/*
 * Copyright (C) 2020  Joshua Minter
 *
 * This file is part of ReplaySorcery.
 *
 * ReplaySorcery is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ReplaySorcery is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ReplaySorcery.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef RS_AUDIO_H
#define RS_AUDIO_H
#include "../device/device.h"
#include "../encoder/encoder.h"
#include "abuffer.h"
#include "rsbuild.h"
#include <libavcodec/avcodec.h>
#ifdef RS_BUILD_PTHREAD_FOUND
#include <pthread.h>
#endif

typedef struct RSAudioThread {
   RSDevice device;
   RSAudioBuffer buffer;
   AVFrame *frame;
   volatile int running;
#ifdef RS_BUILD_PTHREAD_FOUND
   pthread_t *thread;
   pthread_mutex_t *mutex;
#endif
} RSAudioThread;

int rsAudioThreadCreate(RSAudioThread *thread);
void rsAudioThreadDestroy(RSAudioThread *thread);
void rsAudioThreadLock(RSAudioThread *thread);
void rsAudioThreadUnlock(RSAudioThread *thread);

#endif
