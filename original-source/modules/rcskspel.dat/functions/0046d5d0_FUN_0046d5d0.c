/*
 * FUN_0046d5d0 at 0046d5d0
 * undefined FUN_0046d5d0(void)
 * Address ranges: 0046d5d0-0046d64e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046d5d0(int param_1)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  float local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  fVar1 = ABS((0.5 - *(float *)(param_1 + 0x68) / *(float *)(param_1 + 100)) * 2.9);
  fVar1 = fVar1 * fVar1;
  FUN_0046c510();
  iVar2 = FUN_004583d0();
  local_8 = *(undefined4 *)(iVar2 + 4);
  local_4 = *(undefined4 *)(iVar2 + 8);
  local_c = fVar1;
  if (*(float *)(param_1 + 0x68) + *(float *)(param_1 + 0x68) < *(float *)(param_1 + 100)) {
    local_c = -fVar1;
  }
  pfVar3 = &local_c;
  FUN_0046c510(pfVar3);
  FUN_00458400(pfVar3);
  return;
}

