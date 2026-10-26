/*
 * FUN_0041aab8 at 0041aab8
 * undefined FUN_0041aab8(void)
 * Address ranges: 0041aab8-0041ab40;0041ab58-0041abbe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041aab8(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar2;
  undefined2 extraout_var;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_70;
  undefined1 *puStack_6c;
  int *piStack_68;
  undefined4 uStack_64;
  undefined1 *puStack_60;
  undefined1 *puStack_5c;
  uint *puStack_4c;
  byte bStack_48;
  undefined1 auStack_47 [63];
  int *piStack_8;
  
  puStack_5c = &stack0xfffffffc;
  puStack_4c = (uint *)0x0;
  puStack_60 = &LAB_0041abbf;
  uStack_64 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_64;
  piStack_68 = (int *)0x41aae7;
  (**(code **)(*param_2 + 4))(param_2,&bStack_48,1);
  piStack_68 = (int *)0x41aaf6;
  (**(code **)(*param_2 + 4))(param_2,auStack_47,bStack_48);
  piStack_68 = (int *)0x41ab01;
  FUN_00403d74((int *)&puStack_4c,&bStack_48);
  piStack_68 = (int *)0x41ab0e;
  iVar1 = FUN_0041a4fc(DAT_0047b5d8,puStack_4c);
  piStack_8 = (int *)0x0;
  if (iVar1 != 0) {
    piStack_68 = (int *)0x41ab1c;
    piStack_8 = (int *)(**(code **)(iVar1 + 0xc))(iVar1,1);
    puStack_6c = &LAB_0041ab41;
    uStack_70 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_70;
    piStack_68 = (int *)&stack0xfffffffc;
    (**(code **)(*piStack_8 + 0x30))(piStack_8,param_2);
    *in_FS_OFFSET = uStack_70;
  }
  piStack_68 = (int *)0x41ab60;
  FUN_00402eac((int *)param_1[1]);
  param_1[1] = (int)piStack_8;
  uVar2 = extraout_ECX;
  if (piStack_8 != (int *)0x0) {
    piStack_8[3] = (int)param_1;
    piStack_68 = piStack_8;
    puStack_6c = (undefined1 *)0x41ab7e;
    iVar1 = FUN_004030a0(param_1,CONCAT22(extraout_var,0xfffd));
    piStack_68[2] = iVar1;
    piStack_8[5] = (int)param_1;
    piStack_68 = piStack_8;
    puStack_6c = (undefined1 *)0x41ab96;
    iVar1 = FUN_004030a0(param_1,CONCAT22((short)((uint)iVar1 >> 0x10),0xfffc));
    piStack_68[4] = iVar1;
    uVar2 = extraout_ECX_00;
  }
  piStack_68 = (int *)0x41aba9;
  FUN_00403088(param_1,param_1,uVar2);
  *in_FS_OFFSET = uStack_64;
  puStack_5c = &LAB_0041abc6;
  puStack_60 = (undefined1 *)0x41abbe;
  FUN_00403b50((int *)&puStack_4c);
  return;
}

