/*
 * FUN_00461b44 at 00461b44
 * undefined __register FUN_00461b44(int param_1, uint param_2, char param_3)
 * Address ranges: 00461b44-00461c58
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00461b44(int param_1,uint param_2,char param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  uint *local_c;
  char local_5;
  
  puStack_18 = &stack0xfffffffc;
  local_c = (uint *)0x0;
  puStack_1c = &LAB_00461c59;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  local_5 = param_3;
  piVar1 = (int *)FUN_00461ea8(param_1,(undefined4 *)&DAT_00461c70,(byte)param_2);
  if (piVar1 != (int *)0x0) {
    if ((byte)((byte)param_2 - 4) < 2) {
      if (local_5 == '\x01') {
        FUN_00403be8((int *)&local_c,0x461c7c);
      }
      else {
        FUN_00403be8((int *)&local_c,0x461c9c);
      }
    }
    else if (local_5 == '\x01') {
      FUN_00403be8((int *)&local_c,0x461cbc);
    }
    else {
      iVar2 = FUN_00458eac(*(int *)(*(int *)PTR_DAT_0047c670 + 0x88),param_2);
      if (iVar2 == 0x25) {
        FUN_00403be8((int *)&local_c,0x461cfc);
      }
      else if (iVar2 == 0x26) {
        FUN_00403be8((int *)&local_c,0x461cdc);
      }
      else if (iVar2 == 0x27) {
        FUN_00403be8((int *)&local_c,0x461d1c);
      }
      else if (iVar2 == 0x28) {
        FUN_00403be8((int *)&local_c,0x461d3c);
      }
      else {
        FUN_00403be8((int *)&local_c,0x461d5c);
      }
    }
  }
  FUN_00452c0c(piVar1[0x4b],local_c);
  FUN_0043fb28(piVar1);
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_00461c60;
  puStack_1c = (undefined1 *)0x461c58;
  FUN_00403b50((int *)&local_c);
  return;
}

