/*
 * FUN_0040f26c at 0040f26c
 * undefined __cdecl FUN_0040f26c(undefined4 * param_1, uint * param_2, uint * param_3)
 * Address ranges: 0040f26c-0040f30f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0040f26c(undefined4 *param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_0040f241();
  if (iVar1 == -1) {
    FUN_0040187a((byte *)s__s__d____Unable_to_allocate_new_D_00432f74);
  }
  if (param_1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)(DAT_0043d7c8 + iVar1 * 0xd8);
    *puVar2 = *param_1;
    puVar2[1] = param_1[1];
    puVar2[2] = param_1[2];
    puVar2[3] = param_1[3];
  }
  FUN_0041f7a0((uint *)(DAT_0043d7c8 + 0x10 + iVar1 * 0xd8),param_2);
  FUN_0041f7a0((uint *)(DAT_0043d7c8 + 0x74 + iVar1 * 0xd8),param_3);
  DAT_00432c00 = iVar1;
  return;
}

