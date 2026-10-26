/*
 * FUN_0049ced0 at 0049ced0
 * undefined FUN_0049ced0(void)
 * Address ranges: 0049ced0-0049d27a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049ced0(uint param_1)

{
  uint uVar1;
  float fVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  float10 fVar11;
  int iStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_34;
  float fStack_30;
  uint uStack_2c;
  float fStack_28;
  uint uStack_24;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  uint uStack_14;
  uint uStack_10;
  
  uVar1 = param_1;
  iVar3 = FUN_004b96d0(param_1);
  if (iVar3 == 0) {
    FUN_004afee0(s__s__d____File_open_failed_for_fi_004face0,
                 s_D__work_rcsk_Code_Engine_Prog_rd_004fbc10,0x42,uVar1);
  }
  FUN_004bf930(&param_1,4,1,iVar3);
  uVar1 = param_1;
  if (DAT_006a5bf4 != 0) {
    if ((DAT_006a5bf4 == 1) &&
       (FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_006a5c15,&DAT_006a5bfc,
                     DAT_006a5bec), DAT_006a5be8 != (uint *)0x0)) {
      FUN_004945d0(3);
    }
    if (DAT_006a5bf4 != 0) {
      FUN_004bc150(DAT_006a5bf8);
      DAT_006a5bf4 = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  if ((int)uVar1 < 0) {
    FUN_004afee0(s__s__d____T_ARRAY_construction__i_004de770,
                 s_______Libs_Win3DLib_Include_arra_004fa4c0,0x107,&DAT_006a5c15,&DAT_006a5bfc,uVar1
                );
  }
  puVar4 = operator_new(uVar1 * 0x60 + 4);
  if (puVar4 == (uint *)0x0) {
    DAT_006a5be8 = (uint *)0x0;
  }
  else {
    *puVar4 = uVar1;
    DAT_006a5be8 = puVar4 + 1;
    if (-1 < (int)(uVar1 - 1)) {
      puVar4 = puVar4 + 8;
      uVar8 = uVar1;
      do {
        uVar8 = uVar8 - 1;
        puVar9 = &DAT_006a5c90;
        puVar10 = puVar4;
        for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar10 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        }
        puVar4 = puVar4 + 0x18;
      } while (uVar8 != 0);
    }
  }
  DAT_006a5bec = uVar1;
  DAT_006a5bf0 = 0;
  DAT_006a5bf8 = operator_new(uVar1);
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,&DAT_006a5c15,&DAT_006a5bfc,DAT_006a5bec)
  ;
  DAT_006a5bf4 = 1;
  iVar7 = 0;
  if (0 < (int)uVar1) {
    do {
      iVar5 = iVar7 + 1;
      *(undefined1 *)((int)DAT_006a5bf8 + iVar7) = 0;
      iVar7 = iVar5;
    } while (iVar5 < (int)uVar1);
  }
  iStack_4c = 0;
  if ((int)param_1 < 1) {
LAB_0049d25c:
    FUN_004b9840(iVar3);
    return;
  }
LAB_0049d05c:
  FUN_004bf930(&uStack_24,4,1,iVar3);
  FUN_004bf930(&uStack_20,4,1,iVar3);
  FUN_004bf930(&uStack_1c,4,1,iVar3);
  FUN_004bf930(&fStack_30,4,1,iVar3);
  FUN_004bf930(&uStack_2c,4,1,iVar3);
  FUN_004bf930(&fStack_28,4,1,iVar3);
  uVar1 = uStack_2c;
  fVar2 = fStack_30;
  fStack_34 = fStack_28;
  uStack_10 = uStack_1c;
  fStack_3c = fStack_30;
  uStack_18 = uStack_24;
  uStack_14 = uStack_20;
  iVar7 = DAT_006a5bf0;
  if (DAT_006a5bf4 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,
                 s_______Libs_Win3DLib_Include_arra_004fa4c0,0xb9,&DAT_006a5bfc,DAT_006a5bec,
                 &DAT_006a5c15);
    iVar7 = DAT_006a5bf0;
  }
  for (; iVar7 < (int)DAT_006a5bec; iVar7 = iVar7 + 1) {
    if (*(char *)((int)DAT_006a5bf8 + iVar7) == '\0') goto LAB_0049d26d;
  }
  iVar7 = 0;
  if (0 < DAT_006a5bf0) {
    do {
      if (*(char *)((int)DAT_006a5bf8 + iVar7) == '\0') goto LAB_0049d26d;
      iVar7 = iVar7 + 1;
    } while (iVar7 < DAT_006a5bf0);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,
               s_______Libs_Win3DLib_Include_arra_004fa4c0,0xce,&DAT_006a5bfc,DAT_006a5bec,
               &DAT_006a5c15);
  iVar7 = -1;
  goto LAB_0049d17a;
LAB_0049d26d:
  *(undefined1 *)((int)DAT_006a5bf8 + iVar7) = 1;
  DAT_006a5bf0 = iVar7;
LAB_0049d17a:
  puVar4 = DAT_006a5be8 + iVar7 * 0x18;
  *puVar4 = uStack_18;
  fStack_44 = 0.0;
  puVar4[1] = uStack_14;
  puVar4[3] = (uint)fVar2;
  puVar4[2] = uStack_10;
  puVar4[4] = uVar1;
  fStack_48 = fStack_3c;
  puVar4[5] = (uint)fStack_34;
  fStack_40 = fStack_34;
  puVar4[0x17] = (uint)SQRT(fStack_3c * fStack_3c + fStack_34 * fStack_34);
  fVar11 = (float10)FUN_00405f40(&fStack_48);
  fVar11 = SQRT(fVar11);
  pfVar6 = (float *)FUN_00405f20((float)((float10)fStack_48 / fVar11),
                                 (float)((float10)fStack_44 / fVar11),
                                 (float)((float10)fStack_40 / fVar11));
  fStack_48 = *pfVar6;
  fStack_44 = pfVar6[1];
  fStack_40 = pfVar6[2];
  fVar11 = (float10)fpatan((float10)fStack_40,(float10)fStack_48);
  iStack_4c = iStack_4c + 1;
  puVar4[6] = (uint)(float)(((fVar11 - (float10)3.1415927 * (float10)0.5) * (float10)_DAT_004fc8f4)
                           / (float10)6.2831855);
  if ((int)param_1 <= iStack_4c) goto LAB_0049d25c;
  goto LAB_0049d05c;
}

