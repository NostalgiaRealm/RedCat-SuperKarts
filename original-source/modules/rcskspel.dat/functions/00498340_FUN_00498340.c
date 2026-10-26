/*
 * FUN_00498340 at 00498340
 * undefined FUN_00498340(void)
 * Address ranges: 00498340-004986f0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_00498340(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  puVar1 = param_1 + 0x3b;
  param_1[0x3e] = 0;
  _strncpy((char *)(param_1 + 0x40),s_Follow_positions_004fb3f4,0x19);
  _strncpy((char *)((int)param_1 + 0x119),s_D3DVECTOR_004fb3e8,0x19);
  if (param_1[0x3e] != 0) {
    FUN_00405f70();
  }
  *puVar1 = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,(int)param_1 + 0x119,param_1 + 0x40,0);
  param_1[0x3f] = 0;
  param_1[0x3e] = 0;
  *(undefined4 *)((int)param_1 + 0x13e) = 0;
  _strncpy((char *)((int)param_1 + 0x146),s_Follow_orientations_004fb3d4,0x19);
  _strncpy((char *)((int)param_1 + 0x15f),s_D3DMATRIX_004fb3c8,0x19);
  FUN_00499580();
  *param_1 = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[2] = DAT_00680c08;
  param_1[3] = DAT_00680c0c;
  param_1[4] = DAT_00680c10;
  puVar7 = &DAT_006a5c90;
  puVar8 = param_1 + 5;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  iVar6 = 0;
  param_1[0x15] = DAT_00680c08;
  param_1[0x16] = DAT_00680c0c;
  param_1[0x17] = DAT_00680c10;
  param_1[0x18] = DAT_00680c08;
  param_1[0x19] = DAT_00680c0c;
  uVar2 = DAT_00680c10;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1a] = uVar2;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x22] = 0x3f800000;
  param_1[0x1f] = 0;
  param_1[0x23] = 0x3f800000;
  param_1[0x20] = 1;
  param_1[0x24] = 0x3f800000;
  param_1[0x21] = 0;
  param_1[0x25] = 0x3f800000;
  param_1[0x26] = 0x3f800000;
  param_1[0x27] = 0x3f800000;
  param_1[0x28] = DAT_00680c08;
  param_1[0x29] = DAT_00680c0c;
  uVar2 = DAT_00680c10;
  param_1[0x2e] = 0xffffffff;
  param_1[0x2a] = uVar2;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0x3f800000;
  param_1[0x2f] = DAT_00680c08;
  param_1[0x30] = DAT_00680c0c;
  uVar2 = DAT_00680c10;
  param_1[0x32] = 0xffffffff;
  param_1[0x31] = uVar2;
  param_1[0x33] = DAT_00680c08;
  param_1[0x34] = DAT_00680c0c;
  uVar2 = DAT_00680c10;
  param_1[0x36] = 0xffffffff;
  param_1[0x35] = uVar2;
  param_1[0x37] = DAT_00680c08;
  param_1[0x38] = DAT_00680c0c;
  uVar2 = DAT_00680c10;
  param_1[0x3a] = 0;
  param_1[0x39] = uVar2;
  if (param_1[0x3e] != 0) {
    if (param_1[0x3e] == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,(int)param_1 + 0x119,param_1 + 0x40,
                   param_1[0x3c]);
      FUN_004bc150(*puVar1);
    }
    if (param_1[0x3e] != 0) {
      FUN_004bc150(param_1[0x3f]);
      param_1[0x3e] = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  pvVar3 = operator_new(0x3c);
  if (pvVar3 == (void *)0x0) {
    pvVar3 = (void *)0x0;
  }
  else {
    FUN_00402950(pvVar3,0xc,5,FUN_00423920);
  }
  *puVar1 = pvVar3;
  param_1[0x3c] = 5;
  param_1[0x3d] = 0;
  pvVar3 = operator_new(5);
  param_1[0x3f] = pvVar3;
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,(int)param_1 + 0x119,param_1 + 0x40,
               param_1[0x3c]);
  param_1[0x3e] = 1;
  iVar4 = 0;
  do {
    iVar5 = iVar4 + 1;
    *(undefined1 *)(iVar4 + param_1[0x3f]) = 0;
    iVar4 = iVar5;
  } while (iVar5 < 5);
  if (*(int *)((int)param_1 + 0x13e) != 0) {
    FUN_00405f70();
  }
  pvVar3 = operator_new(0x140);
  if (pvVar3 == (void *)0x0) {
    pvVar3 = (void *)0x0;
  }
  else {
    FUN_00402950(pvVar3,0x40,5,FUN_00423920);
  }
  *(void **)((int)param_1 + 0x132) = pvVar3;
  *(undefined4 *)((int)param_1 + 0x136) = 5;
  *(undefined4 *)((int)param_1 + 0x13a) = 0;
  pvVar3 = operator_new(5);
  *(void **)((int)param_1 + 0x142) = pvVar3;
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,(int)param_1 + 0x15f,(int)param_1 + 0x146
               ,*(undefined4 *)((int)param_1 + 0x136));
  *(undefined4 *)((int)param_1 + 0x13e) = 1;
  do {
    iVar6 = iVar6 + 1;
    *(undefined1 *)(*(int *)((int)param_1 + 0x142) + -1 + iVar6) = 0;
  } while (iVar6 < 5);
  iVar6 = 5;
  do {
    FUN_004994f0();
    FUN_004994f0();
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return param_1;
}

