/*
 * FUN_00464f30 at 00464f30
 * undefined FUN_00464f30(void)
 * Address ranges: 00464f30-00464fb6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00464f30(int param_1)

{
  undefined4 uVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;
  
  fVar2 = *(float *)(param_1 + 4) / 1.2;
  iVar5 = 0;
  do {
    FUN_00464c80(iVar5);
    iVar3 = FUN_004583d0();
    uVar1 = *(undefined4 *)(iVar3 + 8);
    puVar4 = (undefined4 *)FUN_004583d0();
    local_c = *puVar4;
    puVar4 = &local_c;
    local_8 = fVar2 * 1.25 + (1.0 - fVar2) * 0.4;
    local_4 = uVar1;
    FUN_00464c80(iVar5);
    FUN_00458400(puVar4);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  return;
}

