/*
 * FUN_00442160 at 00442160
 * undefined __register FUN_00442160(int * param_1, undefined4 param_2)
 * Address ranges: 00442160-004421e6;004421ee-004421f2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00442160(int *param_1,undefined4 param_2)

{
  bool bVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined1 local_18 [16];
  int *local_8;
  
  puStack_20 = (undefined1 *)0x442174;
  local_8 = param_1;
  bVar1 = FUN_00445a20((int)param_1);
  if ((bVar1) && ((*(byte *)(local_8 + 8) & 8) == 0)) {
    if ((short)local_8[0x48] == 0) {
      puStack_20 = (undefined1 *)0x4421a0;
      FUN_004421f4((int)local_8);
      puStack_24 = &LAB_004421e7;
      uStack_28 = *in_FS_OFFSET;
      *in_FS_OFFSET = &uStack_28;
      puStack_20 = &stack0xfffffffc;
      (**(code **)(*local_8 + 0x40))(local_8,local_18);
      (**(code **)(*local_8 + 0x88))(local_8,param_2,local_18);
      *in_FS_OFFSET = uStack_28;
      puStack_20 = (undefined1 *)0x4421ee;
      *(ushort *)(local_8 + 0x11) = *(ushort *)(local_8 + 0x11) & 0xffef;
      puStack_24 = (undefined1 *)0x4421e6;
      FUN_004421fc((int)local_8);
      return;
    }
    *(ushort *)(local_8 + 0x11) = *(ushort *)(local_8 + 0x11) | 0x10;
  }
  return;
}

