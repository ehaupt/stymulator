/*	file: sound.cpp 

	This file is a part of STYMulator - GNU/Linux YM player

	Player & ST-Sound GPL library GNU/Linux port by Grzegorz Tomasz Stanczyk
	Project Page: http://atariarea.krap.pl/stymulator
	
	Original ST-Sound GPL library by Arnaud Carre (http://leonard.oxg.free.fr)

-----------------------------------------------------------------------------
 *   STYMulator is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   STYMulator is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with STYMulator; if not, write to the                           *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
---------------------------------------------------------------------------*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "sound.h"

int format = AFMT_S16_LE;

int err, dir;
int resample = 1;
unsigned int rate = 44100;
unsigned int channels = 1;
unsigned int period_time = 100000;

int period_size; //4410

int oss_init(int audio_fd) {
    period_size = 4096;
    
    if (ioctl(audio_fd, SNDCTL_DSP_SETFMT, &format) < 0) {
        printf("Cannot set sample format\n");
        return -1;
    }
    
    if (ioctl(audio_fd, SNDCTL_DSP_CHANNELS, &channels) < 0) {
        printf("Cannot set audio channels\n");
        return -1;
    }

    if (ioctl(audio_fd, SNDCTL_DSP_SPEED, &rate) < 0) {
        printf("Cannot set sample rate\n");
        return -1;
    }

    return 0;
}
