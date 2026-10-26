/*
 * FUN_0048ca60 at 0048ca60
 * undefined FUN_0048ca60(void)
 * Address ranges: 0048ca60-0048d451
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0048ca60(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  undefined4 *puVar10;
  float10 fVar11;
  undefined1 local_69;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 *local_58;
  uint local_54;
  undefined4 local_50;
  undefined4 local_4c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d15b0;
  local_c = ExceptionList;
  local_5c = 0;
  local_58 = (undefined4 *)0x0;
  local_54 = 0;
  puVar3 = (undefined4 *)(*(int *)(param_1 + 0x1180) * 0xd0 + 0x9c + DAT_0067ee20);
  ExceptionList = &local_c;
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  iVar4 = DAT_0067ee20 + *(int *)(param_1 + 0x1180) * 0xd0;
  iVar7 = *(int *)(iVar4 + 0xc);
  if (*(char *)(param_1 + 0x1198) != '\0') {
    if (*(int *)(param_1 + 0x1194) == 3) {
      if (*(int *)(param_1 + 0x1180) == DAT_0053be28) {
        FUN_004371f0();
        uVar2 = FUN_00437ea0(DAT_00508610);
        local_5c = CONCAT31(local_5c._1_3_,local_69);
        FUN_0040b4f0(0);
        uVar5 = 0xffffffff;
        pcVar9 = s_DISAPP_004fa148;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar9;
          pcVar9 = pcVar9 + 1;
        } while (cVar1 != '\0');
        FUN_0040b540(s_DISAPP_004fa148,~uVar5 - 1);
        puVar3 = &local_5c;
        local_4 = 0;
        FUN_004371f0(uVar2,puVar3);
        FUN_00437b10(uVar2,puVar3);
        local_4 = 0xffffffff;
        FUN_0040b4f0(1);
      }
      else {
        iVar6 = 0;
        iVar4 = DAT_00508610;
        if (0 < DAT_00508610) {
          do {
            if (*(int *)(param_1 + 0x1180) == (&DAT_00503ef0)[iVar6 * 0x47]) {
              FUN_004371f0();
              uVar2 = FUN_00437ea0(iVar6);
              local_5c = CONCAT31(local_5c._1_3_,local_69);
              FUN_0040b4f0(0);
              uVar5 = 0xffffffff;
              pcVar9 = s_DISAPP_004fa150;
              do {
                if (uVar5 == 0) break;
                uVar5 = uVar5 - 1;
                cVar1 = *pcVar9;
                pcVar9 = pcVar9 + 1;
              } while (cVar1 != '\0');
              FUN_0040b540(s_DISAPP_004fa150,~uVar5 - 1);
              puVar3 = &local_5c;
              local_4 = 1;
              FUN_004371f0(uVar2,puVar3);
              FUN_00437b10(uVar2,puVar3);
              local_4 = 0xffffffff;
              FUN_0040b4f0(1);
              iVar4 = DAT_00508610;
              iVar6 = DAT_00508610;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar4);
        }
      }
    }
    iVar4 = *(int *)(param_1 + 0x1194);
    puVar3 = (undefined4 *)(iVar7 * 0xa9 + 0x10 + DAT_006a5c38);
    puVar10 = local_4c;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar10 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar10 = puVar10 + 1;
    }
    FUN_004a17c0(local_4c,&DAT_0067df70 + iVar4 * 0x40,local_4c);
    puVar3 = local_4c;
    puVar10 = (undefined4 *)(iVar7 * 0xa9 + 0x10 + DAT_006a5c38);
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar10 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar10 = puVar10 + 1;
    }
    iVar7 = *(int *)(param_1 + 0x1194) + 1;
    *(int *)(param_1 + 0x1194) = iVar7;
    if (iVar7 == 0x14) {
      *(undefined4 *)(param_1 + 0x1194) = 0;
      *(undefined1 *)(param_1 + 0x1198) = 0;
    }
    goto LAB_0048d329;
  }
  if (*(int *)(param_1 + 0x1194) == 0) {
    if (*(char *)(param_1 + 0x11ac) == '\0') {
      if (DAT_0053ba08 == 0) {
        if (DAT_0053ba70 == 1) {
          uVar2 = 0;
        }
        else {
LAB_0048d036:
          uVar2 = 1;
        }
      }
      else {
        if (DAT_0053ba70 == 1) goto LAB_0048d036;
        uVar2 = 0;
      }
      local_64 = FUN_00493430(*(undefined4 *)(iVar4 + 0x1c),0,uVar2);
      cVar1 = FUN_0048d930(&local_64);
      if (cVar1 == '\0') {
        *(undefined4 *)(param_1 + 0x1194) = 0x13;
        *(undefined1 *)(param_1 + 0x1198) = 1;
        puVar3 = (undefined4 *)(iVar7 * 0xa9 + 0x10 + DAT_006a5c38);
        puVar10 = local_4c;
        for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar10 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar10 = puVar10 + 1;
        }
        FUN_004a17c0(local_4c,&DAT_0067e430,local_4c);
        puVar3 = local_4c;
        puVar10 = (undefined4 *)(iVar7 * 0xa9 + 0x10 + DAT_006a5c38);
        for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar10 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar10 = puVar10 + 1;
        }
        puVar3 = (undefined4 *)(*(int *)(param_1 + 0x1180) * 0xd0 + 0x9c + DAT_0067ee20);
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[2] = 0;
        ExceptionList = local_c;
        return;
      }
      puVar3 = (undefined4 *)(local_64 * 0x50 + 8 + DAT_00680ae0);
      iVar4 = DAT_006a5c38 + *(int *)(*(int *)(param_1 + 0x1180) * 0xd0 + 0xc + DAT_0067ee20) * 0xa9
      ;
      *(undefined4 *)(iVar4 + 0x50) = *puVar3;
      *(undefined4 *)(iVar4 + 0x54) = puVar3[1];
      *(undefined4 *)(iVar4 + 0x58) = puVar3[2];
      iVar4 = *(int *)(param_1 + 0x1180) * 0xd0 + DAT_0067ee20;
      uVar2 = FUN_00450690(*(int *)(param_1 + 0x1180));
      *(undefined4 *)(iVar4 + 0x1c) = uVar2;
      FUN_00493540(*(int *)(param_1 + 0x1180),
                   *(undefined4 *)(*(int *)(param_1 + 0x1180) * 0xd0 + 0x1c + DAT_0067ee20),1);
      fVar11 = (float10)FUN_00430ff0(*(undefined4 *)(param_1 + 0x1180));
      iVar4 = DAT_006a5c38 + *(int *)(*(int *)(param_1 + 0x1180) * 0xd0 + 0xc + DAT_0067ee20) * 0xa9
      ;
      puVar3 = (undefined4 *)(iVar4 + 0x50);
      uVar2 = *(undefined4 *)(iVar4 + 0x58);
      *puVar3 = *puVar3;
    }
    else {
      local_64 = FUN_0048bf80(*(undefined4 *)(iVar4 + 0x24),0);
      if (local_64 < 0) goto LAB_0048ce72;
      puVar3 = (undefined4 *)(local_64 * 0x50 + 8 + DAT_00680ae0);
      cVar1 = FUN_0048c170(*(undefined4 *)(param_1 + 0x1180),*puVar3,puVar3[1],puVar3[2]);
      if (cVar1 == '\0') {
        *(undefined4 *)(param_1 + 0x1194) = 0x13;
        *(undefined1 *)(param_1 + 0x1198) = 1;
        puVar3 = (undefined4 *)(iVar7 * 0xa9 + 0x10 + DAT_006a5c38);
        puVar10 = local_4c;
        for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar10 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar10 = puVar10 + 1;
        }
        FUN_004a17c0(local_4c,&DAT_0067e430,local_4c);
        puVar3 = local_4c;
        puVar10 = (undefined4 *)(iVar7 * 0xa9 + 0x10 + DAT_006a5c38);
        for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar10 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar10 = puVar10 + 1;
        }
        puVar3 = (undefined4 *)(*(int *)(param_1 + 0x1180) * 0xd0 + 0x9c + DAT_0067ee20);
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[2] = 0;
        ExceptionList = local_c;
        return;
      }
      puVar3 = (undefined4 *)(local_64 * 0x50 + 8 + DAT_00680ae0);
      iVar4 = DAT_006a5c38 + *(int *)(*(int *)(param_1 + 0x1180) * 0xd0 + 0xc + DAT_0067ee20) * 0xa9
      ;
      *(undefined4 *)(iVar4 + 0x50) = *puVar3;
      *(undefined4 *)(iVar4 + 0x54) = puVar3[1];
      *(undefined4 *)(iVar4 + 0x58) = puVar3[2];
      iVar4 = *(int *)(param_1 + 0x1180) * 0xd0 + DAT_0067ee20;
      uVar2 = FUN_00450690(*(int *)(param_1 + 0x1180));
      *(undefined4 *)(iVar4 + 0x1c) = uVar2;
      FUN_00493540(*(int *)(param_1 + 0x1180),
                   *(undefined4 *)(*(int *)(param_1 + 0x1180) * 0xd0 + 0x1c + DAT_0067ee20),1);
      fVar11 = (float10)FUN_00430ff0(*(undefined4 *)(param_1 + 0x1180));
      iVar4 = DAT_006a5c38 + *(int *)(*(int *)(param_1 + 0x1180) * 0xd0 + 0xc + DAT_0067ee20) * 0xa9
      ;
      puVar3 = (undefined4 *)(iVar4 + 0x50);
      uVar2 = *(undefined4 *)(iVar4 + 0x58);
      *puVar3 = *puVar3;
    }
    local_58 = (undefined4 *)(float)fVar11;
    puVar3[1] = local_58;
    puVar3[2] = uVar2;
    if (*(int *)(param_1 + 0x1180) == DAT_0053be28) {
      iVar6 = *(int *)(*(int *)(param_1 + 0x1180) * 0xd0 + 0xc + DAT_0067ee20);
      iVar4 = DAT_006a5c38 + iVar6 + 0x50 + iVar6 * 0xa8;
      _DAT_0053be44 = *(undefined4 *)(DAT_006a5c38 + iVar6 + 0x50 + iVar6 * 0xa8);
      DAT_0053be48 = *(undefined4 *)(iVar4 + 4);
      DAT_0053be4c = *(undefined4 *)(iVar4 + 8);
      DAT_0053be34 = 0;
    }
  }
LAB_0048ce72:
  if (*(int *)(param_1 + 0x1194) == 3) {
    if (*(int *)(param_1 + 0x1180) == DAT_0053be28) {
      FUN_004371f0();
      local_60 = FUN_00437ea0(DAT_00508610);
      uVar5 = 0xffffffff;
      pcVar9 = (char *)&DAT_004fa158;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5 - 1;
      local_5c = CONCAT31(local_5c._1_3_,local_69);
      local_58 = (undefined4 *)0x0;
      local_54 = 0;
      local_50 = 0;
      cVar1 = FUN_0040b600(uVar5,1);
      if (cVar1 != '\0') {
        puVar3 = &DAT_004fa158;
        puVar10 = local_58;
        for (uVar8 = uVar5 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar10 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar10 = puVar10 + 1;
        }
        for (uVar8 = uVar5 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
          *(undefined1 *)puVar10 = *(undefined1 *)puVar3;
          puVar3 = (undefined4 *)((int)puVar3 + 1);
          puVar10 = (undefined4 *)((int)puVar10 + 1);
        }
        *(undefined1 *)((int)local_58 + uVar5) = 0;
        local_54 = uVar5;
      }
      puVar3 = &local_5c;
      local_4 = 2;
      uVar2 = local_60;
      FUN_004371f0(local_60,puVar3);
      FUN_00437b10(uVar2,puVar3);
      local_4 = 0xffffffff;
      if (local_58 != (undefined4 *)0x0) {
        cVar1 = *(char *)((int)local_58 + -1);
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150((char *)((int)local_58 + -1));
        }
        else {
          *(char *)((int)local_58 + -1) = cVar1 + -1;
        }
      }
    }
    else {
      iVar6 = 0;
      iVar4 = DAT_00508610;
      if (0 < DAT_00508610) {
        do {
          if (*(int *)(param_1 + 0x1180) == (&DAT_00503ef0)[iVar6 * 0x47]) {
            FUN_004371f0();
            local_60 = FUN_00437ea0(iVar6);
            local_5c = CONCAT31(local_5c._1_3_,local_69);
            local_58 = (undefined4 *)0x0;
            local_54 = 0;
            local_50 = 0;
            uVar5 = 0xffffffff;
            pcVar9 = (char *)&DAT_004fa160;
            do {
              if (uVar5 == 0) break;
              uVar5 = uVar5 - 1;
              cVar1 = *pcVar9;
              pcVar9 = pcVar9 + 1;
            } while (cVar1 != '\0');
            uVar5 = ~uVar5 - 1;
            cVar1 = FUN_0040b600(uVar5,1);
            if (cVar1 != '\0') {
              puVar3 = &DAT_004fa160;
              puVar10 = local_58;
              for (uVar8 = uVar5 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                *puVar10 = *puVar3;
                puVar3 = puVar3 + 1;
                puVar10 = puVar10 + 1;
              }
              for (uVar8 = uVar5 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                *(undefined1 *)puVar10 = *(undefined1 *)puVar3;
                puVar3 = (undefined4 *)((int)puVar3 + 1);
                puVar10 = (undefined4 *)((int)puVar10 + 1);
              }
              *(undefined1 *)((int)local_58 + uVar5) = 0;
              local_54 = uVar5;
            }
            puVar3 = &local_5c;
            local_4 = 3;
            uVar2 = local_60;
            FUN_004371f0(local_60,puVar3);
            FUN_00437b10(uVar2,puVar3);
            local_4 = 0xffffffff;
            if (local_58 != (undefined4 *)0x0) {
              cVar1 = *(char *)((int)local_58 + -1);
              if ((cVar1 == '\0') || (cVar1 == -1)) {
                FUN_004bc150((char *)((int)local_58 + -1));
              }
              else {
                *(char *)((int)local_58 + -1) = cVar1 + -1;
              }
            }
            local_58 = (undefined4 *)0x0;
            local_54 = 0;
            local_50 = 0;
            iVar4 = DAT_00508610;
            iVar6 = DAT_00508610;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar4);
      }
    }
  }
  local_5c = 0;
  local_58 = (undefined4 *)0x0;
  local_54 = 0;
  puVar3 = (undefined4 *)(*(int *)(param_1 + 0x1180) * 0xd0 + 0x9c + DAT_0067ee20);
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  iVar4 = *(int *)(param_1 + 0x1194);
  puVar3 = (undefined4 *)(iVar7 * 0xa9 + 0x10 + DAT_006a5c38);
  puVar10 = local_4c;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar10 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar10 = puVar10 + 1;
  }
  FUN_004a17c0(local_4c,&DAT_0067da70 + iVar4 * 0x40,local_4c);
  puVar3 = local_4c;
  puVar10 = (undefined4 *)(iVar7 * 0xa9 + 0x10 + DAT_006a5c38);
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar10 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar10 = puVar10 + 1;
  }
  iVar7 = *(int *)(param_1 + 0x1194) + 1;
  *(int *)(param_1 + 0x1194) = iVar7;
  if (iVar7 == 0x14) {
    *(undefined4 *)(param_1 + 0x1194) = 0;
    *(undefined1 *)(param_1 + 0x1198) = 1;
    *(undefined1 *)(param_1 + 0x11a0) = 1;
    local_5c = 0;
    local_58 = (undefined4 *)0x0;
    local_54 = 0x40a00000;
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0x1180) * 0xd0 + 0x9c + DAT_0067ee20);
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0x40a00000;
  }
LAB_0048d329:
  FUN_0048d610();
  ExceptionList = local_c;
  return;
}

