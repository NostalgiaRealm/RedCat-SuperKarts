/*
 * FUN_0041e680 at 0041e680
 * undefined __register FUN_0041e680(int param_1, int param_2, uint param_3)
 * Address ranges: 0041e680-0041e720
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041e680(int param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  undefined4 *local_c;
  
  puStack_1c = (undefined1 *)0x41e698;
  FUN_0041e668(param_1);
  puStack_20 = &LAB_0041e721;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  for (local_c = *(undefined4 **)(param_1 + 4);
      (local_c != (undefined4 *)0x0 && ((param_2 != local_c[2] || (param_3 != local_c[3]))));
      local_c = (undefined4 *)*local_c) {
  }
  if (local_c == (undefined4 *)0x0) {
    puStack_1c = &stack0xfffffffc;
    puVar1 = (undefined4 *)FUN_00402714(0x10);
    *puVar1 = *(undefined4 *)(param_1 + 4);
    piVar2 = FUN_0041e734(param_1,param_2,param_3);
    puVar1[1] = piVar2;
    puVar1[2] = param_2;
    puVar1[3] = param_3;
    *(undefined4 **)(param_1 + 4) = puVar1;
  }
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_0041e728;
  puStack_20 = (undefined1 *)0x41e720;
  FUN_0041e674(param_1);
  return;
}

