#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <X11/Xlib.h>
//#include <X11/keysm.h>
#include<GL/glx.h>
#include "log.h"

#define USE_OPENAL_SOUND
#ifdef USE_OPENAL_SOUND
#include </usr/include/AL/alut.h>
#endif //USE_OPENAL_SOUND

struct Global {
/*	int xres, yres;
	Grid grid[MAX_GRID][MAX_GRID];
	Snake snake;
	Rat rat;
	int gridDim;
	int boardDim;
	int gameover;
	int winner;
	Image *marbleImage;
	GLuint marbleTexture;
	Button button[MAXBUTTONS];
	int nbuttons;
*/	//
	ALuint alBufferDrip, alBufferTick;
	ALuint alSourceDrip, alSourceTick;
/*	Global() {
		xres = 800;
		yres = 600;
		gridDim = 40;
		gameover = 0;
		winner = 0;
		nbuttons = 0;
		marbleImage=NULL;
	}
*/   
}gp;



void initSound()
{
	#ifdef USE_OPENAL_SOUND
	alutInit(0, NULL);
	if (alGetError() != AL_NO_ERROR) {
		printf("ERROR: alutInit()\n");
		return;
	}
	//Clear error state.
	alGetError();
	//
	//Setup the listener.
	//Forward and up vectors are used.
	float vec[6] = {0.0f,0.0f,1.0f, 0.0f,1.0f,0.0f};
	alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
	alListenerfv(AL_ORIENTATION, vec);
	alListenerf(AL_GAIN, 1.0f);
	//
	//Buffer holds the sound information.
	gp.alBufferDrip = alutCreateBufferFromFile("./sounds/drip.wav");
	gp.alBufferTick = alutCreateBufferFromFile("./sounds/tick.wav");
	//
	//Source refers to the sound.
	//Generate a source, and store it in a buffer.
	alGenSources(1, &gp.alSourceDrip);
	alSourcei(gp.alSourceDrip, AL_BUFFER, gp.alBufferDrip);
	//Set volume and pitch to normal, no looping of sound.
	alSourcef(gp.alSourceDrip, AL_GAIN, 1.0f);
	alSourcef(gp.alSourceDrip, AL_PITCH, 1.0f);
	alSourcei(gp.alSourceDrip, AL_LOOPING, AL_FALSE);
	if (alGetError() != AL_NO_ERROR) {
		printf("ERROR: setting source\n");
		return;
	}
	//Generate a source, and store it in a buffer.
	alGenSources(1, &gp.alSourceTick);
	alSourcei(gp.alSourceTick, AL_BUFFER, gp.alBufferTick);
	//Set volume and pitch to normal, no looping of sound.
	alSourcef(gp.alSourceTick, AL_GAIN, 1.0f);
	alSourcef(gp.alSourceTick, AL_PITCH, 1.0f);
	alSourcei(gp.alSourceTick, AL_LOOPING, AL_FALSE);
	if (alGetError() != AL_NO_ERROR) {
		printf("ERROR: setting source\n");
		return;
	}
	#endif //USE_OPENAL_SOUND
}

void cleanupSound()
{
	#ifdef USE_OPENAL_SOUND
	//First delete the source.
	alDeleteSources(1, &gp.alSourceDrip);
	alDeleteSources(1, &gp.alSourceTick);
	//Delete the buffer.
	alDeleteBuffers(1, &gp.alBufferDrip);
	alDeleteBuffers(1, &gp.alBufferTick);
	//Close out OpenAL itself.
	//Get active context.
	ALCcontext *Context = alcGetCurrentContext();
	//Get device for active context.
	ALCdevice *Device = alcGetContextsDevice(Context);
	//Disable context.
	alcMakeContextCurrent(NULL);
	//Release context(s).
	alcDestroyContext(Context);
	//Close device.
	alcCloseDevice(Device);
	#endif //USE_OPENAL_SOUND
}

void playSound(ALuint source)
{
	#ifdef USE_OPENAL_SOUND
	alSourcePlay(source);
	#endif //USE_OPENAL_SOUND
}


