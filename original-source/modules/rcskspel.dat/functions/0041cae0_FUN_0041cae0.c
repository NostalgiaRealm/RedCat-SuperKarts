/*
 * FUN_0041cae0 at 0041cae0
 * undefined FUN_0041cae0(void)
 * Address ranges: 0041cae0-0041cb6a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041cae0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = FUN_004906b0(4);
  puVar3 = (undefined4 *)
           (*(int *)(param_1 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + DAT_006a5c38 + 0x10);
  puVar4 = (undefined4 *)(DAT_006a5c38 + iVar1 * 0xa9 + 0x10);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_004906b0(4);
  FUN_004a09e0();
  return;
}

