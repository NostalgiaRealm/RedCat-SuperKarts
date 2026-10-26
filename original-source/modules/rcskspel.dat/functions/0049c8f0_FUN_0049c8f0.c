/*
 * FUN_0049c8f0 at 0049c8f0
 * undefined FUN_0049c8f0(void)
 * Address ranges: 0049c8f0-0049c904
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0049c8f0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(param_1 + 4);
  iVar2 = 2;
  do {
    *puVar1 = 0xffffffff;
    puVar1 = (undefined4 *)((int)puVar1 + 9);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

