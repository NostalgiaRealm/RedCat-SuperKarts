/*
 * FUN_0040535c at 0040535c
 * undefined __register FUN_0040535c(undefined4 param_1, undefined4 param_2, undefined1 * param_3)
 * Address ranges: 0040535c-00405396;004053a1-004053b5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040535c(undefined4 param_1,undefined4 param_2,undefined1 *param_3)

{
  undefined4 *puVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  
  for (puVar1 = DAT_0047b020; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    puStack_20 = &LAB_00405397;
    uStack_24 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_24;
    puStack_1c = &stack0xfffffffc;
    (*(code *)puVar1[1])(param_1,param_2,param_3);
    *in_FS_OFFSET = uStack_24;
    param_2 = uStack_24;
    param_3 = puStack_1c;
  }
  return;
}

