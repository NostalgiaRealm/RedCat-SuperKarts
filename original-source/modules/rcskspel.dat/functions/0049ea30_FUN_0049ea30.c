/*
 * FUN_0049ea30 at 0049ea30
 * undefined FUN_0049ea30(void)
 * Address ranges: 0049ea30-0049ea62
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0049ea30(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0x224);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(param_1 + 0x264) = *param_3;
  *(undefined4 *)(param_1 + 0x268) = param_3[1];
  *(undefined4 *)(param_1 + 0x26c) = param_3[2];
  return;
}

