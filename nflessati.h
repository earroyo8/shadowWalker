#ifndef _NFLESSATI_H_
#define _NFLESSATI_H_

extern void initSound(void);
#ifdef USE_OPENAL_SOUND
extern void initSound();
extern void cleanupSound();
extern void playSound(ALuint source);
#endif //USE_OPENAL_SOUND

#endif
