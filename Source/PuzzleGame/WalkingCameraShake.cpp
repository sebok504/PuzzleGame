// Fill out your copyright notice in the Description page of Project Settings.


#include "WalkingCameraShake.h"

UWalkingCameraShake::UWalkingCameraShake()
{
	OscillationDuration = 0.25f;
	OscillationBlendInTime = 0.1f;
	OscillationBlendOutTime = 0.2f;

	RotOscillation.Pitch.Amplitude = 0.6f;
	RotOscillation.Pitch.Frequency = 7.5f;
	RotOscillation.Pitch.InitialOffset = EInitialOscillatorOffset::EOO_OffsetRandom;
	RotOscillation.Pitch.Waveform = EOscillatorWaveform::SineWave;

	RotOscillation.Yaw.Amplitude = 0.4f;
	RotOscillation.Yaw.Frequency = 6.0f;
	RotOscillation.Yaw.InitialOffset = EInitialOscillatorOffset::EOO_OffsetRandom;
	RotOscillation.Yaw.Waveform = EOscillatorWaveform::SineWave;

	RotOscillation.Roll.Amplitude = 0.4f;
	RotOscillation.Roll.Frequency = 3.0f;
	RotOscillation.Roll.InitialOffset = EInitialOscillatorOffset::EOO_OffsetRandom;
	RotOscillation.Roll.Waveform = EOscillatorWaveform::SineWave;

	bSingleInstance = true;
}
