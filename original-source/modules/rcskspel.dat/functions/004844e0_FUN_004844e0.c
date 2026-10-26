/*
 * FUN_004844e0 at 004844e0
 * undefined FUN_004844e0(void)
 * Address ranges: 004844e0-00484869
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004844e0(int param_1)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float10 extraout_ST0;
  float local_394 [12];
  uint auStack_364 [4];
  float afStack_354 [177];
  double local_90;
  uint *local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  double local_74;
  undefined2 local_6c;
  undefined2 local_6a;
  undefined2 local_68;
  undefined2 local_66;
  undefined2 local_64;
  undefined2 local_62;
  undefined2 local_60;
  undefined2 local_5e;
  undefined2 local_5c;
  undefined2 local_5a;
  undefined2 local_58;
  undefined2 local_56;
  undefined2 local_54;
  undefined2 local_52;
  undefined2 local_50;
  undefined2 local_4e;
  undefined2 local_4c;
  undefined2 local_4a;
  undefined2 local_48;
  undefined2 local_46;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined2 local_38;
  undefined2 local_36;
  undefined2 local_34;
  undefined2 local_32;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined2 local_28;
  undefined2 local_26;
  float *local_24;
  uint *local_20;
  float *local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004d1445;
  local_10 = ExceptionList;
  local_14 = &stack0xfffffc60;
  local_52 = 0x13;
  local_3e = 0x13;
  local_6c = 0;
  local_6a = 1;
  local_68 = 3;
  local_66 = 4;
  local_64 = 6;
  local_62 = 7;
  local_60 = 9;
  local_5e = 10;
  local_5c = 0xc;
  local_5a = 0xd;
  local_58 = 0xf;
  local_56 = 0x10;
  local_54 = 0x12;
  local_50 = 0x15;
  local_4e = 0x16;
  local_4c = 0;
  local_4a = 1;
  local_48 = 2;
  local_46 = 1;
  local_44 = 0x17;
  local_42 = 0x16;
  local_40 = 0x14;
  local_3c = 0x11;
  local_3a = 0x10;
  local_38 = 0xe;
  local_36 = 0xd;
  local_34 = 0xb;
  local_32 = 10;
  local_30 = 8;
  local_2e = 7;
  local_2c = 5;
  local_2a = 4;
  local_28 = 2;
  local_26 = 1;
  local_84 = 200;
  local_80 = 0x96;
  local_7c = 0x3c;
  local_78 = 0xf;
  local_8 = 0;
  ExceptionList = &local_10;
  for (local_18 = 0; iVar6 = local_18, local_18 < 0x18; local_18 = local_18 + 3) {
    fVar1 = *(float *)(param_1 + 0x18);
    fVar8 = (float10)local_18 * (float10)3.1415927 * (float10)0.083333336;
    local_1c = (float *)(float)fVar8;
    fVar8 = (float10)fsin(fVar8);
    fVar8 = fVar8 * (float10)*(float *)(param_1 + 4);
    fVar9 = (float10)local_84;
    local_394[local_18 * 8] = (float)((float10)*(float *)(param_1 + 0x14) - fVar9 * fVar8);
    fVar10 = (float10)fcos((float10)(float)local_1c);
    local_394[iVar6 * 8 + 1] = fVar1;
    fVar10 = fVar10 * (float10)*(float *)(param_1 + 4);
    local_74 = (double)fVar10;
    local_24 = local_394 + iVar6 * 8 + 6;
    local_394[iVar6 * 8 + 2] = (float)(fVar10 * fVar9 + (float10)*(float *)(param_1 + 0x1c));
    local_394[iVar6 * 8 + 4] = 0.0;
    local_394[iVar6 * 8 + 5] = 0.0;
    fVar9 = (float10)local_80;
    fVar1 = *(float *)(param_1 + 0x14);
    local_394[iVar6 * 8 + 6] = 0.45;
    local_394[iVar6 * 8 + 7] = 0.15;
    local_1c = local_394 + iVar6 * 8 + 7;
    local_394[iVar6 * 8 + 8] = (float)((float10)fVar1 - fVar9 * fVar8);
    fVar10 = (float10)fsin(((float10)3.1415927 * (float10)*(float *)(param_1 + 4)) /
                           (float10)*(float *)(param_1 + 0xc));
    local_394[iVar6 * 8 + 9] =
         (float)(fVar10 * (float10)local_78 + (float10)*(float *)(param_1 + 0x18));
    local_394[iVar6 * 8 + 10] =
         (float)(fVar9 * (float10)local_74 + (float10)*(float *)(param_1 + 0x1c));
    fVar1 = *(float *)(param_1 + 0xc);
    auStack_364[iVar6 * 8] = 0xffaf00;
    if (*(float *)(param_1 + 4) <= fVar1 * 0.5) {
      iVar5 = 0xff;
      iVar7 = iVar6;
    }
    else {
      iVar5 = __ftol();
      iVar5 = 0xff - iVar5;
      iVar7 = local_18;
      fVar8 = extraout_ST0;
    }
    local_90 = (double)local_7c;
    fVar1 = *(float *)(param_1 + 0x14);
    fVar9 = (float10)local_7c;
    auStack_364[iVar6 * 8] = iVar5 << 0x18 | 0xffaf00;
    auStack_364[iVar6 * 8 + 1] = 0;
    local_20 = auStack_364 + iVar6 * 8 + 2;
    auStack_364[iVar6 * 8 + 2] = 0x3ee66666;
    fVar2 = *(float *)(param_1 + 0x18);
    auStack_364[iVar6 * 8 + 3] = 0x3e19999a;
    pfVar4 = local_1c;
    local_88 = auStack_364 + iVar6 * 8 + 3;
    afStack_354[iVar6 * 8] = (float)((float10)fVar1 - fVar9 * fVar8);
    afStack_354[iVar6 * 8 + 1] = fVar2;
    pfVar3 = local_24;
    afStack_354[iVar6 * 8 + 2] =
         (float)((float10)local_90 * (float10)local_74 + (float10)*(float *)(param_1 + 0x1c));
    afStack_354[iVar6 * 8 + 4] = 0.0;
    afStack_354[iVar6 * 8 + 5] = 0.0;
    afStack_354[iVar6 * 8 + 6] = 0.45;
    afStack_354[iVar6 * 8 + 7] = 0.15;
    FUN_004afce0(s_index__f_tu__f_tv__f_004f9b04,iVar7,(double)*pfVar3,(double)*pfVar4);
    FUN_004afce0(s_index__f_tu__f_tv__f_004f9b1c,local_18 + 1);
  }
  (**(code **)(*DAT_006a621c + 0x78))(DAT_006a621c,5,2,local_394,0x18,&local_6c,0x12,0);
  iVar6 = (**(code **)(*DAT_006a621c + 0x78))(DAT_006a621c,5,2,local_394,0x18,&local_48,0x12,0);
  if (iVar6 != 0) {
    FUN_004afee0(s__s___d__DramPrimitive_error_004f9b58,s_D__work_rcsk_Code_game_Par_Main__004f9b34,
                 0x475);
  }
  ExceptionList = local_10;
  return;
}

