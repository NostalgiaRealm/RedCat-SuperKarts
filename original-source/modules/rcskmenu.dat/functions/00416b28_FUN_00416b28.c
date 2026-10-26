/*
 * FUN_00416b28 at 00416b28
 * undefined __register FUN_00416b28(int param_1, byte * param_2)
 * Address ranges: 00416b28-00416bfb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00416b28(int param_1,byte *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  undefined4 *local_c;
  
  puStack_18 = (undefined1 *)0x416b43;
  uVar1 = FUN_00416a9c(param_2,(uint)*(ushort *)(param_1 + 0x20));
  puStack_18 = (undefined1 *)0x416b4d;
  FUN_00416b10(param_1);
  puStack_1c = &LAB_00416bfc;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  puStack_18 = &stack0xfffffffc;
  for (local_c = *(undefined4 **)(param_1 + 4); local_c != (undefined4 *)0x0;
      local_c = (undefined4 *)*local_c) {
    if ((short)uVar1 == *(short *)(local_c + 3)) {
      uVar2 = FUN_00407ce4(local_c + 4,(int *)param_2,(uint)*(ushort *)(param_1 + 0x20));
      if ((char)uVar2 != '\0') break;
    }
  }
  if (local_c == (undefined4 *)0x0) {
    local_c = (undefined4 *)FUN_00402714(*(ushort *)(param_1 + 0x20) + 0x10);
    *local_c = *(undefined4 *)(param_1 + 4);
    local_c[1] = 0;
    local_c[2] = *(undefined4 *)param_2;
    *(short *)(local_c + 3) = (short)uVar1;
    FUN_0040282c((undefined4 *)param_2,local_c + 4,(uint)*(ushort *)(param_1 + 0x20));
    *(undefined4 **)(param_1 + 4) = local_c;
  }
  local_c[1] = local_c[1] + 1;
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_00416c03;
  puStack_1c = (undefined1 *)0x416bfb;
  FUN_00416b1c(param_1);
  return;
}

