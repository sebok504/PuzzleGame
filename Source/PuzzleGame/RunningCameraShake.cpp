// Fill out your copyright notice in the Description page of Project Settings.


#include "RunningCameraShake.h"

URunningCameraShake::URunningCameraShake()
{
	OscillationDuration = 0.25f;
	OscillationBlendInTime = 0.1f;
	OscillationBlendOutTime = 0.2f;

	RotOscillation.Pitch.Amplitude = 0.8f;
	RotOscillation.Pitch.Frequency = 18.f;
	RotOscillation.Pitch.InitialOffset = EInitialOscillatorOffset::EOO_OffsetRandom;
	RotOscillation.Pitch.Waveform = EOscillatorWaveform::SineWave;

	RotOscillation.Yaw.Amplitude = 0.6f;
	RotOscillation.Yaw.Frequency = 9.f;
	RotOscillation.Yaw.InitialOffset = EInitialOscillatorOffset::EOO_OffsetRandom;
	RotOscillation.Yaw.Waveform = EOscillatorWaveform::SineWave;

	RotOscillation.Roll.Amplitude = 0.4f;
	RotOscillation.Roll.Frequency = 7.0f;
	RotOscillation.Roll.InitialOffset = EInitialOscillatorOffset::EOO_OffsetRandom;
	RotOscillation.Roll.Waveform = EOscillatorWaveform::SineWave;

	bSingleInstance = true;
}
