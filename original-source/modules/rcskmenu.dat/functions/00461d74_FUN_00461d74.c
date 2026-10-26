/*
 * FUN_00461d74 at 00461d74
 * undefined __register FUN_00461d74(int param_1)
 * Address ranges: 00461d74-00461e58
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00461d74(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  uint *local_10;
  uint *local_c;
  int local_8;
  
  puStack_20 = &stack0xfffffffc;
  local_c = (uint *)0x0;
  local_10 = (uint *)0x0;
  puStack_24 = &LAB_00461e59;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  uVar3 = 0;
  local_8 = param_1;
  do {
    iVar1 = FUN_00461fb0(local_8,(undefined4 *)&DAT_00461e70,(byte)uVar3);
    if (iVar1 != 0) {
      iVar2 = FUN_00458eac(*(int *)(*(int *)PTR_DAT_0047c670 + 0x88),uVar3);
      if (iVar2 < 1) {
        FUN_0043f67c(iVar1,(uint *)0x0);
      }
      else if ((iVar2 - 0x41U < 0x1a) || (iVar2 - 0x61U < 0x1a)) {
        FUN_00403cf8((int *)&local_c,iVar2);
        FUN_0043f67c(iVar1,local_c);
      }
      else if ((iVar2 == 0xd) || ((iVar2 - 0x10U < 3 || (iVar2 - 0x20U < 9)))) {
        FUN_00461e74(local_8,iVar2,(int *)&local_10);
        FUN_0043f67c(iVar1,local_10);
      }
      else {
        FUN_0043f67c(iVar1,(uint *)0x0);
      }
    }
    uVar3 = uVar3 + 1;
  } while ((char)uVar3 != '\x06');
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_00461e60;
  puStack_24 = (undefined1 *)0x461e58;
  FUN_00403b74((int *)&local_10,2);
  return;
}

