/*
 * FUN_00464a00 at 00464a00
 * undefined FUN_00464a00(void)
 * Address ranges: 00464a00-00464a6f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00464a00(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  do {
    uVar3 = 1;
    FUN_00464c80(iVar2);
    FUN_00458460(uVar3);
    FUN_00464c80(iVar2);
    puVar1 = (undefined4 *)FUN_004583d0();
    local_c = *puVar1;
    puVar4 = &local_c;
    local_4 = puVar1[2];
    local_8 = 0x3fa00000;
    FUN_00464c80(iVar2);
    FUN_00458400(puVar4);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  return;
}

