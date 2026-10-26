/*
 * FUN_00457cd0 at 00457cd0
 * undefined __register FUN_00457cd0(int param_1, int param_2)
 * Address ranges: 00457cd0-00457da5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00457cd0(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int *in_FS_OFFSET;
  int iStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined *local_18;
  int local_14 [2];
  undefined *local_c;
  int local_8;
  
  puStack_24 = &stack0xfffffffc;
  local_8 = 0;
  local_c = (undefined *)0x0;
  local_14[1] = 0;
  local_14[0] = 0;
  local_18 = (undefined *)0x0;
  puStack_28 = &LAB_00457da6;
  iStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_2c;
  FUN_00407f60(param_2,local_14 + 1);
  FUN_00403e90(&local_8,3);
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_18);
  FUN_004081c4(local_18,local_14);
  iVar1 = local_8;
  FUN_00403e90((int *)&local_c,4);
  uVar3 = FUN_0040811c(local_c);
  if ((char)uVar3 == '\x01') {
    bVar2 = FUN_0040812c(local_c);
    if (bVar2) {
      *(undefined1 *)(param_1 + 0xc + param_2) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
      iVar4 = FUN_00457c88(param_1,param_2);
      if (iVar4 < 0) {
        iVar4 = FUN_00457cac(param_1,param_2);
      }
      FUN_004578f4(param_1,iVar4);
    }
  }
  *in_FS_OFFSET = iVar1;
  FUN_00403b74((int *)&local_18,5);
  return;
}

