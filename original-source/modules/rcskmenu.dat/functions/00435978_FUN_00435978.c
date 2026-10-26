/*
 * FUN_00435978 at 00435978
 * undefined __register FUN_00435978(ushort param_1, int * param_2)
 * Address ranges: 00435978-00435b60
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00435978(ushort param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  undefined4 *local_10;
  undefined4 *local_c;
  undefined4 uStack_8;
  
  puStack_1c = &stack0xfffffffc;
  local_c = (undefined4 *)0x0;
  local_10 = (undefined4 *)0x0;
  uStack_8 = (uint)param_1 << 0x10;
  uVar2 = uStack_8;
  puStack_20 = &LAB_00435b61;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  uStack_8._2_1_ = (byte)param_1;
  uVar1 = (uint)uStack_8._2_1_;
  uStack_8 = uVar2;
  if (uStack_8._2_1_ < 0x2d) {
    if (uVar1 - 8 < 2) {
      uVar2 = (uint)uStack_8._2_1_;
      puStack_1c = &stack0xfffffffc;
      FUN_00403be8((int *)&local_c,*(int *)(&DAT_0047b800 + uVar2 * 4));
      goto LAB_00435aed;
    }
    if (uVar1 == 0xd) {
      puStack_1c = &stack0xfffffffc;
      FUN_00403be8((int *)&local_c,DAT_0047b82c);
      goto LAB_00435aed;
    }
    if (uVar1 == 0x1b) {
      puStack_1c = &stack0xfffffffc;
      FUN_00403be8((int *)&local_c,DAT_0047b828);
      goto LAB_00435aed;
    }
    if (uVar1 - 0x20 < 9) {
      bVar3 = uStack_8._2_1_ + 4;
      puStack_1c = &stack0xfffffffc;
      FUN_00403be8((int *)&local_c,*(int *)(&DAT_0047b7a0 + (uint)bVar3 * 4));
      goto LAB_00435aed;
    }
  }
  else if (uStack_8._2_1_ < 0x41) {
    if (uVar1 - 0x2d < 2) {
      bVar3 = uStack_8._2_1_ + 0xd;
      puStack_1c = &stack0xfffffffc;
      FUN_00403be8((int *)&local_c,(&DAT_0047b76c)[bVar3]);
      goto LAB_00435aed;
    }
    if (uVar1 - 0x30 < 10) {
      uVar2 = (uint)uStack_8._2_1_;
      puStack_1c = &stack0xfffffffc;
      FUN_00403cf8((int *)&local_c,uVar2);
      goto LAB_00435aed;
    }
  }
  else {
    if (uVar1 - 0x41 < 0x1a) {
      uVar2 = (uint)uStack_8._2_1_;
      FUN_00403cf8((int *)&local_c,uVar2);
      goto LAB_00435aed;
    }
    if (uVar1 - 0x60 < 10) {
      uVar2 = (uint)uStack_8._2_1_;
      puStack_1c = &stack0xfffffffc;
      FUN_00403cf8((int *)&local_c,uVar2 - 0x30);
      goto LAB_00435aed;
    }
    if (uVar1 - 0x70 < 0x18) {
      uVar2 = (uint)uStack_8._2_1_;
      puStack_1c = &stack0xfffffffc;
      FUN_00407f60(uVar2 - 0x6f,(int *)&local_10);
      FUN_00403e1c((int *)&local_c,(undefined4 *)&DAT_00435b78,local_10);
      goto LAB_00435aed;
    }
  }
  puStack_1c = &stack0xfffffffc;
  FUN_00435924(param_1,(int *)&local_c);
LAB_00435aed:
  if (local_c == (undefined4 *)0x0) {
    FUN_00403b50(param_2);
  }
  else {
    FUN_00403b50(param_2);
    if ((uStack_8 & 0x20000000) != 0) {
      FUN_00403dd8(param_2,DAT_0047b85c);
    }
    if ((uStack_8 & 0x40000000) != 0) {
      FUN_00403dd8(param_2,DAT_0047b860);
    }
    if ((uStack_8 & 0x80000000) != 0) {
      FUN_00403dd8(param_2,DAT_0047b864);
    }
    FUN_00403dd8(param_2,local_c);
  }
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_00435b68;
  puStack_20 = (undefined1 *)0x435b60;
  FUN_00403b74((int *)&local_10,2);
  return;
}

