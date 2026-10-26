/*
 * FUN_004551a0 at 004551a0
 * undefined __register FUN_004551a0(int * param_1)
 * Address ranges: 004551a0-00455302
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004551a0(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar4;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar5;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  byte *local_c;
  undefined4 local_8;
  
  puStack_1c = &stack0xfffffffc;
  local_c = (byte *)0x0;
  puStack_20 = &LAB_00455303;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  local_8 = 0;
  cVar1 = '\0';
  iVar2 = FUN_00403dd0(param_1[5]);
  if (iVar2 != 0) {
    iVar2 = FUN_00455638((int)param_1);
    if (iVar2 == 1) {
      FUN_00403be8((int *)&local_c,param_1[5]);
      uVar4 = extraout_ECX_00;
      uVar5 = extraout_EDX_00;
      goto LAB_004551f3;
    }
  }
  FUN_00403be8((int *)&local_c,param_1[2]);
  uVar4 = extraout_ECX;
  uVar5 = extraout_EDX;
LAB_004551f3:
  piVar3 = FUN_00454f20(&DAT_00454e9c,uVar5,uVar4);
  iVar2 = FUN_00454f84((int)piVar3,local_c);
  FUN_004556fc((int)param_1,0);
  piVar3 = (int *)0x0;
  if (iVar2 != 0) {
    FUN_004555d4((int)param_1,*(uint **)(iVar2 + 0x2d0),'\a',(int *)&local_c);
    piVar3 = FUN_00454f20(&DAT_00454e9c,extraout_EDX_01,extraout_ECX_01);
    piVar3 = (int *)FUN_00454f84((int)piVar3,local_c);
  }
  if (piVar3 == (int *)0x0) {
    local_8 = 1;
  }
  else {
    (**(code **)(*piVar3 + 0xe4))();
    while( true ) {
      if ((cVar1 == '\x04') || (piVar3 == (int *)0x0)) goto LAB_004552e1;
      (**(code **)(*param_1 + 4))();
      cVar1 = (**(code **)(*piVar3 + 0xe8))();
      (**(code **)(*piVar3 + 0xec))();
      if (cVar1 == '\x04') break;
      FUN_004555d4((int)param_1,(uint *)piVar3[0xb4],cVar1,(int *)&local_c);
      FUN_00403ba4(param_1 + 5,(undefined4 *)local_c);
      piVar3 = FUN_00454f20(&DAT_00454e9c,extraout_EDX_02,extraout_ECX_02);
      piVar3 = (int *)FUN_00454f84((int)piVar3,local_c);
      if (piVar3 == (int *)0x0) {
        local_8 = 1;
        goto LAB_004552ed;
      }
      (**(code **)(*piVar3 + 0xe4))();
      (**(code **)(*param_1 + 8))();
    }
    local_8 = 1;
LAB_004552e1:
    FUN_004556fc((int)param_1,1);
  }
LAB_004552ed:
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_0045530a;
  puStack_20 = (undefined1 *)0x455302;
  FUN_00403b50((int *)&local_c);
  return;
}

