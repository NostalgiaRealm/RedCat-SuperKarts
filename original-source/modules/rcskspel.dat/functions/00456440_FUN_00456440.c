/*
 * FUN_00456440 at 00456440
 * undefined FUN_00456440(void)
 * Address ranges: 00456440-00456706
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00456440(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  uint extraout_ECX;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  float *pfVar12;
  undefined4 uVar13;
  float *pfVar14;
  undefined4 uVar15;
  char *local_34;
  int local_30 [3];
  int local_24;
  undefined1 local_20 [4];
  int local_1c;
  float local_18;
  undefined4 local_14;
  undefined4 local_10;
  float local_c;
  int local_8;
  undefined4 local_4;
  
  FUN_004afce0(s_CShotBonus__SetState_004f2020);
  if (param_2 == 1) {
    *(undefined1 *)(param_1 + 0x2c) = 0;
    uVar3 = FUN_004500d0();
    FUN_0048a480(uVar3);
    FUN_0048a890(uVar3);
    cVar1 = FUN_00417e90(*(undefined4 *)(param_1 + 0x24));
    uVar3 = DAT_0053be28;
    if (cVar1 == '\0') {
      uVar3 = (&DAT_005081bc)[*(int *)(param_1 + 0x24) * 0x1c];
    }
    FUN_00487950(uVar3);
    FUN_00487c00(uVar3);
    iVar2 = DAT_0054406c;
    piVar5 = (int *)(param_1 + 0x20);
    piVar4 = (int *)FUN_004571f0(local_30 + 2,piVar5);
    local_30[0] = *piVar4;
    if ((local_30[0] == DAT_0054406c) || (*piVar5 < *(int *)(local_30[0] + 0xc))) {
      local_30[2] = DAT_0054406c;
      piVar4 = local_30 + 2;
    }
    else {
      piVar4 = local_30;
    }
    if (*piVar4 != iVar2) {
      local_30[0] = *piVar5;
      local_30[1] = 0;
      piVar4 = (int *)FUN_00456d10(local_20,local_30);
      local_30[2] = *piVar4;
      local_24 = piVar4[1];
      piVar4 = (int *)FUN_00480350(local_30 + 2,&local_24);
      local_8 = piVar4[1];
      if (*(int *)(*piVar4 + 0x10) == param_1) {
        local_30[0] = *piVar5;
        local_30[1] = 0;
        piVar5 = (int *)FUN_00456d10(&local_c,local_30);
        local_30[2] = *piVar5;
        local_24 = piVar5[1];
        piVar5 = (int *)FUN_00480350(local_30 + 2,&local_24);
        local_1c = piVar5[1];
        *(undefined4 *)(*piVar5 + 0x10) = 0;
      }
    }
  }
  else {
    if (param_2 != 2) {
      local_34 = s_Unallowed_state_004f2038;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&local_34,&DAT_004d5538);
    }
    iVar2 = FUN_004500b0();
    if (iVar2 == 1) {
      iVar2 = FUN_004503c0();
      if (iVar2 == 2) {
        local_18 = DAT_0067da50 - 6.0;
        local_14 = DAT_0067da54;
        local_10 = DAT_0067da58;
        uVar6 = (uint)DAT_0067da60 & 0xffffff00;
        local_8 = DAT_0067da64;
        local_c = DAT_0067da60 + 6.0;
        local_4 = DAT_0067da68;
        pfVar14 = &local_c;
        uVar8 = 0x41000000;
        pfVar12 = &local_18;
        uVar3 = FUN_004500d0(pfVar12,pfVar14,0x41000000,uVar6);
        FUN_0048a480(uVar3);
        FUN_0048a6d0(uVar3,pfVar12,pfVar14,uVar8,uVar6);
      }
      else {
        uVar6 = extraout_ECX & 0xffffff00;
        uVar15 = 1;
        uVar13 = 0x41000000;
        uVar11 = 1;
        uVar10 = 0;
        uVar9 = 5;
        uVar8 = 0;
        puVar7 = &DAT_0067da50;
        uVar3 = FUN_004500d0(&DAT_0067da50,0,5,0,1,0x41000000,1,uVar6);
        FUN_0048a480(uVar3);
        FUN_0048a570(uVar3,puVar7,uVar8,uVar9,uVar10,uVar11,uVar13,uVar15,uVar6);
      }
      iVar2 = FUN_0044fb50();
      if ((iVar2 == 1) && (iVar2 = FUN_0044fbc0(), 1 < iVar2)) {
        pfVar14 = &local_c;
        uVar3 = 0x41200000;
        local_c = 0.0;
        local_8 = 0x41c80000;
        local_4 = 0xc2040000;
        FUN_00487950(param_1,pfVar14,0x41200000);
        FUN_00487af0(param_1,pfVar14,uVar3);
        FUN_0044fa70(2);
        return;
      }
    }
  }
  FUN_0044fa70(param_2);
  return;
}

