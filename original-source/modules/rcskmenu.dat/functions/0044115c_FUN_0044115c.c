/*
 * FUN_0044115c at 0044115c
 * undefined FUN_0044115c(void)
 * Address ranges: 0044115c-00441240
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044115c(int *param_1,int *param_2,char param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar3;
  undefined4 *in_FS_OFFSET;
  undefined1 uVar4;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  uint *puStack_c;
  int iStack_8;
  
  puStack_1c = &stack0xfffffffc;
  iStack_8 = 0;
  puStack_c = (uint *)0x0;
  puStack_20 = &LAB_00441241;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  uVar2 = FUN_00403024(param_2,(int)&PTR_FUN_0042618c);
  if ((char)uVar2 == '\0') goto LAB_00441226;
  if (param_3 == '\0') {
LAB_004411ba:
    FUN_0043f67c((int)param_1,(uint *)param_2[0x15]);
  }
  else {
    FUN_0043f64c((int)param_1,&iStack_8);
    uVar4 = iStack_8 == 0;
    if ((bool)uVar4) goto LAB_004411ba;
    FUN_0043f64c((int)param_1,(int *)&puStack_c);
    FUN_00403ee0(puStack_c,(uint *)param_1[2]);
    if ((bool)uVar4) goto LAB_004411ba;
  }
  if (param_3 == '\0') {
LAB_004411d3:
    (**(code **)(*param_1 + 0x5c))(param_1,*(undefined1 *)((int)param_2 + 0x59));
    uVar2 = extraout_ECX_00;
    uVar3 = extraout_EDX_00;
  }
  else {
    cVar1 = (**(code **)(*param_1 + 0x4c))();
    uVar2 = extraout_ECX;
    uVar3 = extraout_EDX;
    if (cVar1 == '\x01') goto LAB_004411d3;
  }
  if ((param_3 == '\0') || (param_1[0x1c] == 0)) {
    FUN_00403ba4(param_1 + 0x1c,(undefined4 *)param_2[0x18]);
    uVar2 = extraout_ECX_01;
    uVar3 = extraout_EDX_01;
  }
  if ((param_3 == '\0') || (*(char *)((int)param_1 + 0x47) == '\x01')) {
    FUN_0043f564(param_1,CONCAT31((int3)((uint)uVar3 >> 8),*(undefined1 *)((int)param_2 + 0x6a)),
                 uVar2);
  }
  if ((param_3 == '\0') || (*(short *)((int)param_1 + 0x10a) == 0)) {
    param_1[0x42] = param_2[0xc];
    param_1[0x43] = param_2[0xd];
  }
LAB_00441226:
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_00441248;
  puStack_20 = (undefined1 *)0x441240;
  FUN_00403b74((int *)&puStack_c,2);
  return;
}

