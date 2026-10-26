/*
 * FUN_00461958 at 00461958
 * undefined __register FUN_00461958(int param_1, undefined4 param_2, ushort * param_3)
 * Address ranges: 00461958-00461af7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00461958(int param_1,undefined4 param_2,ushort *param_3)

{
  byte bVar1;
  undefined4 *puVar2;
  ushort uVar3;
  undefined4 uVar4;
  undefined2 uVar6;
  int iVar5;
  undefined4 extraout_EDX;
  undefined3 uVar8;
  undefined4 extraout_EDX_00;
  uint uVar7;
  undefined4 extraout_EDX_01;
  uint extraout_EDX_02;
  uint extraout_EDX_03;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  undefined4 *local_10;
  uint *local_c;
  undefined4 *local_8;
  
  puStack_1c = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  local_c = (uint *)0x0;
  local_10 = (undefined4 *)0x0;
  puStack_20 = &LAB_00461af8;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  if (*(char *)(param_1 + 0x354) == '\0') goto LAB_00461add;
  FUN_0045c720(0x33);
  if (*(char *)(param_1 + 0x34e) == '\0') goto LAB_00461add;
  uVar8 = (undefined3)((uint)extraout_EDX >> 8);
  if ((ushort)(*param_3 - 0x41) < 0x1a) {
    *param_3 = *param_3 + 0x20;
    uVar4 = FUN_00458eb4(*(int *)(*(int *)PTR_DAT_0047c670 + 0x88),
                         CONCAT31(uVar8,*(undefined1 *)(param_1 + 0x34c)),(uint)*param_3);
    if ((char)uVar4 != '\0') {
      FUN_0045c4c8(0x36,(int *)&local_8);
      puVar2 = local_8;
      FUN_0045c4f0(0x15,(int *)&local_c);
      FUN_00460df0(local_c,puVar2,4);
      goto LAB_00461add;
    }
    FUN_00458ea4(*(int *)(*(int *)PTR_DAT_0047c670 + 0x88),
                 CONCAT31((int3)((uint)extraout_EDX_00 >> 8),*(undefined1 *)(param_1 + 0x34c)),
                 (uint)*param_3);
    uVar7 = (uint)*(byte *)(param_1 + 0x34c);
    *(uint *)(&DAT_0047e1c4 + uVar7 * 4) = (uint)*param_3;
  }
  else {
    uVar4 = FUN_00458eb4(*(int *)(*(int *)PTR_DAT_0047c670 + 0x88),
                         CONCAT31(uVar8,*(undefined1 *)(param_1 + 0x34c)),(uint)*param_3);
    if ((char)uVar4 != '\0') {
      FUN_0045c4c8(0x36,(int *)&local_10);
      FUN_00460d08(local_10);
      goto LAB_00461add;
    }
    iVar5 = CONCAT22((short)((uint)uVar4 >> 0x10),*param_3 - 0xd);
    if ((ushort)(*param_3 - 0xd) != 0) {
      uVar3 = (ushort)(iVar5 + -3);
      uVar6 = (undefined2)((uint)(iVar5 + -3) >> 0x10);
      iVar5 = CONCAT22(uVar6,uVar3 - 3);
      if (2 < uVar3) {
        if ((ushort)(uVar3 - 0xb) == 0) {
          *(undefined1 *)(param_1 + 0x34e) = 0;
          FUN_00461b44(param_1,CONCAT31((int3)((uint)extraout_EDX_01 >> 8),2),'\0');
          FUN_00461d74(param_1);
          uVar7 = extraout_EDX_03;
          goto LAB_00461ace;
        }
        iVar5 = CONCAT22(uVar6,uVar3 - 0xb) + -5;
        uVar3 = (ushort)iVar5;
        iVar5 = CONCAT22((short)((uint)iVar5 >> 0x10),uVar3 - 9);
        if (8 < uVar3) {
          FUN_0045c720(0x6e);
          goto LAB_00461add;
        }
      }
    }
    uVar3 = *param_3;
    bVar1 = *(byte *)(param_1 + 0x34c);
    *(uint *)(&DAT_0047e1c4 + (uint)bVar1 * 4) = (uint)uVar3;
    FUN_00458ea4(*(int *)(*(int *)PTR_DAT_0047c670 + 0x88),CONCAT31((int3)((uint)iVar5 >> 8),bVar1),
                 (uint)uVar3);
    uVar7 = extraout_EDX_02;
  }
LAB_00461ace:
  FUN_004620ec(param_1,CONCAT31((int3)(uVar7 >> 8),*(undefined1 *)(param_1 + 0x34c)),'\x01');
LAB_00461add:
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_00461aff;
  puStack_20 = (undefined1 *)0x461af7;
  FUN_00403b74((int *)&local_10,3);
  return;
}

