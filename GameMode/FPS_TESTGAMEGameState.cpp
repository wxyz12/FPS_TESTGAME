// This code was written by 康子秋

#include "FPS_TESTGAMEGameState.h"
#include"Net/UnrealNetwork.h"

void AFPS_TESTGAMEGameState::OnRep_WaveState(EWaveState OldState)
{
	WaveStateChanged(WaveState, OldState);
}
void AFPS_TESTGAMEGameState::SetWaveState(EWaveState NewState)
{

	if (Role == ROLE_Authority)
	{
		EWaveState OldSatet = WaveState;

		WaveState = NewState;
		OnRep_WaveState(OldSatet);
	}

}
void AFPS_TESTGAMEGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const	//成员复制
{

	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AFPS_TESTGAMEGameState, WaveState);

}