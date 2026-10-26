/*
 * FUN_0040ed68 at 0040ed68
 * undefined __register FUN_0040ed68(undefined4 * param_1, char * param_2)
 * Address ranges: 0040ed68-0040ee20
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040ed68(undefined4 *param_1,char *param_2)

{
  short *psVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_12c;
  undefined1 *puStack_128;
  undefined1 *puStack_124;
  byte local_114 [256];
  char *local_14;
  undefined **local_10;
  int local_c;
  char *local_8;
  
  puStack_124 = &stack0xfffffffc;
  local_14 = (char *)0x0;
  puStack_128 = &LAB_0040ee21;
  uStack_12c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_12c;
  local_8 = param_2;
  for (local_10 = (undefined **)FUN_00402df4(param_1); local_10 != &PTR_FUN_0040df7c;
      local_10 = (undefined **)FUN_00402e34((int)local_10)) {
    psVar1 = (short *)FUN_0040ec20((int)local_10);
    if ((psVar1 != (short *)0x0) && (iVar3 = (int)*psVar1, -1 < iVar3 + -1)) {
      local_c = 0;
      do {
        FUN_00402df8(**(int **)(psVar1 + local_c * 2 + 1),local_114);
        FUN_00403d74((int *)&local_14,local_114);
        uVar2 = FUN_00407d58(local_14,local_8);
        if ((char)uVar2 != '\0') goto LAB_0040ee0b;
        local_c = local_c + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  FUN_0040ec98((int)local_8);
LAB_0040ee0b:
  *in_FS_OFFSET = uStack_12c;
  puStack_124 = &LAB_0040ee28;
  puStack_128 = (undefined1 *)0x40ee20;
  FUN_00403b50((int *)&local_14);
  return;
}

