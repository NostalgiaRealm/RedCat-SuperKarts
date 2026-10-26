/*
 * FUN_00443e80 at 00443e80
 * undefined FUN_00443e80(void)
 * Address ranges: 00443e80-00443eec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00443e80(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_40 [8];
  undefined4 local_20 [8];
  
  if (DAT_0053b9c0 != 1) {
    return 0;
  }
  puVar1 = (undefined4 *)FUN_00443d20(local_40,param_1);
  puVar3 = local_40;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = local_40;
  puVar3 = local_20;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_00443db0(param_1,local_20);
  _DAT_0053f4f0 = GetTickCount();
  DAT_0053f4ec = 0;
  return 1;
}

