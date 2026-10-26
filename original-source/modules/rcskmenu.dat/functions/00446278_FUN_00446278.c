/*
 * FUN_00446278 at 00446278
 * undefined1 __register FUN_00446278(int * param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00446278-0044639c;00446430-00446439
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_00446278(int *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  bool bVar2;
  undefined1 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_50;
  undefined1 *puStack_4c;
  undefined1 *puStack_48;
  int local_38;
  int local_34;
  int local_28;
  int local_24;
  int local_18;
  undefined1 local_11;
  undefined4 local_10;
  undefined4 local_c;
  int *local_8;
  
  local_11 = 1;
  puStack_48 = (undefined1 *)0x446296;
  local_10 = param_3;
  local_c = param_2;
  local_8 = param_1;
  bVar2 = FUN_00445a20((int)param_1);
  if ((bVar2) && (*(char *)((int)local_8 + 0x4b) != '\x05')) {
    if ((*(byte *)(local_8 + 8) & 0x10) != 0) {
      puStack_48 = (undefined1 *)0x4462bc;
      iVar4 = FUN_0044268c((int)local_8);
      if (iVar4 < 1) {
        return local_11;
      }
    }
    puStack_48 = (undefined1 *)0x4462d2;
    (**(code **)(*local_8 + 0xa4))(local_8,&local_28);
    puStack_48 = (undefined1 *)0x4462dd;
    (**(code **)(*local_8 + 0x40))(local_8,&local_38);
    puStack_48 = (undefined1 *)0x4462eb;
    (**(code **)(*local_8 + 0x84))(local_8,&local_38);
    puStack_48 = (undefined1 *)0x4462f3;
    FUN_004421f4((int)local_8);
    puStack_4c = &LAB_0044639d;
    uStack_50 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_50;
    puStack_48 = &stack0xfffffffc;
    iVar4 = FUN_0044268c((int)local_8);
    if (-1 < iVar4 + -1) {
      local_18 = 0;
      do {
        piVar5 = (int *)FUN_00442650((int)local_8,local_18);
        if ((*(char *)((int)piVar5 + 0x47) != '\0') ||
           (((*(byte *)(piVar5 + 8) & 0x10) != 0 && ((*(byte *)((int)piVar5 + 0x41) & 4) == 0)))) {
          bVar1 = *(byte *)((int)local_8 + 0x4b);
          if ((bVar1 == 0) || ((byte)(bVar1 - 3) < 2)) {
            iVar7 = local_28 - local_38;
          }
          else {
            iVar7 = 0;
          }
          if (bVar1 < 3) {
            iVar6 = local_24 - local_34;
          }
          else {
            iVar6 = 0;
          }
          (**(code **)(*piVar5 + 0x7c))
                    (piVar5,piVar5[0xc] - iVar7,piVar5[0xd] - iVar6,piVar5[0xf],piVar5[0xe]);
        }
        local_18 = local_18 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    *in_FS_OFFSET = uStack_50;
    puStack_48 = &DAT_004463a4;
    *(ushort *)(local_8 + 0x11) = *(ushort *)(local_8 + 0x11) & 0xffef;
    puStack_4c = (undefined1 *)0x44639c;
    uVar3 = FUN_004421fc((int)local_8);
    return uVar3;
  }
  return local_11;
}

