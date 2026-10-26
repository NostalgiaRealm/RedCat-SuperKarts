/*
 * FUN_004343a4 at 004343a4
 * undefined1 __register FUN_004343a4(int * param_1, int * param_2)
 * Address ranges: 004343a4-00434462;00434487-00434490
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_004343a4(int *param_1,int *param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar6;
  undefined4 extraout_ECX_01;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  
  if (param_2 != (int *)0x0) {
    puStack_20 = (undefined1 *)0x4343bc;
    iVar2 = FUN_00433bb0(param_1);
    puStack_20 = (undefined1 *)0x4343c5;
    iVar3 = FUN_00433bb0(param_2);
    if (iVar2 == iVar3) {
      puStack_20 = (undefined1 *)0x4343d9;
      iVar2 = FUN_00433bb0(param_1);
      uVar6 = extraout_ECX;
      if (iVar2 == 0) {
        puStack_20 = (undefined1 *)0x4343e4;
        iVar2 = FUN_00433bb0(param_2);
        uVar6 = extraout_ECX_00;
        if (iVar2 == 0) {
          return 1;
        }
      }
      puStack_20 = (undefined1 *)0x4343fd;
      piVar4 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040e594,'\x01',uVar6);
      puStack_24 = &LAB_00434480;
      uStack_28 = *in_FS_OFFSET;
      *in_FS_OFFSET = &uStack_28;
      puStack_2c = (undefined1 *)0x434418;
      puStack_20 = &stack0xfffffffc;
      FUN_004348e4(param_1,(int)piVar4);
      puStack_2c = (undefined1 *)0x434424;
      piVar5 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040e594,'\x01',extraout_ECX_01);
      puStack_30 = &LAB_00434463;
      uStack_34 = *in_FS_OFFSET;
      *in_FS_OFFSET = &uStack_34;
      puStack_2c = &stack0xfffffffc;
      FUN_004348e4(param_2,(int)piVar5);
      FUN_00434364(piVar4,piVar5);
      *in_FS_OFFSET = uStack_34;
      puStack_2c = &LAB_0043446a;
      puStack_30 = (undefined1 *)0x434462;
      uVar1 = FUN_00402eac(piVar5);
      return uVar1;
    }
  }
  return 0;
}

