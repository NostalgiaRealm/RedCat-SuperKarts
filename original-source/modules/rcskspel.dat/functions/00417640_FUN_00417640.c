/*
 * FUN_00417640 at 00417640
 * undefined FUN_00417640(void)
 * Address ranges: 00417640-004179cf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00417640(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  char *pcVar11;
  undefined4 *puVar12;
  bool bVar13;
  undefined4 *local_2c;
  int local_28;
  undefined4 *local_24;
  undefined1 local_1c [4];
  undefined4 *local_18;
  uint local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004cceb8;
  local_c = ExceptionList;
  if (DAT_0053ba08 == 0) {
    bVar13 = DAT_0053ba70 != 1;
  }
  else {
    bVar13 = DAT_0053ba70 == 1;
  }
  ExceptionList = &local_c;
  FUN_00417ae0();
  FUN_00417dd0();
  FUN_00417aa0();
  iVar10 = 0;
  local_28 = 0;
  if (0 < DAT_00508610) {
    local_24 = (undefined4 *)&DAT_00503f24;
    local_2c = &DAT_005081b0;
    do {
      cVar1 = FUN_00417e90(local_28);
      iVar3 = DAT_0053be60;
      if (cVar1 == '\0') {
        iVar3 = local_2c[2];
      }
      uVar2 = FUN_00493a20(DAT_0053b9cc - iVar3);
      iVar10 = FUN_00493a70(uVar2,bVar13,iVar10 + 1);
      FUN_004afce0(s__s__d____XXX_Lane_for_racer__d_i_004e11bc,
                   s_D__work_rcsk_Code_game_Car_race__004e1198,0x92,local_28,iVar10);
      switch(*local_2c) {
      case 0:
        uVar7 = 7;
        break;
      case 1:
        uVar7 = 8;
        break;
      case 2:
        uVar7 = 9;
        break;
      default:
        uVar7 = 10;
        break;
      case 4:
        uVar7 = 0xb;
        break;
      case 5:
        uVar7 = 0xc;
        break;
      case 6:
        uVar7 = 0xd;
        break;
      case 7:
        uVar7 = 0xe;
        break;
      case 8:
        uVar7 = 0xf;
        break;
      case 9:
        uVar7 = 0x10;
      }
      iVar3 = FUN_00415f90(1,uVar2,iVar10,bVar13,1,FUN_0040b0b0,FUN_00434c40,3,local_28);
      uVar2 = FUN_00493430(uVar2,iVar10,bVar13,iVar10);
      FUN_00403d90(iVar3,uVar7,uVar2);
      iVar8 = iVar3 * 0xd0;
      *(undefined4 *)(iVar8 + 0x48 + DAT_0067ee20) = 0;
      *(code **)(iVar8 + 0x58 + DAT_0067ee20) = FUN_00416650;
      FUN_0041b760(1,iVar3);
      FUN_004906b0(4);
      FUN_004a09e0();
      local_18 = (undefined4 *)0x0;
      *(undefined4 *)(iVar8 + 0x50 + DAT_0067ee20) = 1;
      local_14 = 0;
      local_10 = 0;
      uVar5 = 0xffffffff;
      pcVar11 = (char *)&DAT_004e11e4;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar11;
        pcVar11 = pcVar11 + 1;
      } while (cVar1 != '\0');
      uVar6 = ~uVar5 - 1;
      uVar5 = FUN_00412a70();
      if (uVar5 < uVar6) {
        FUN_004bc15b();
      }
      if (((local_18 == (undefined4 *)0x0) || (cVar1 = *(char *)((int)local_18 + -1), cVar1 == '\0')
          ) || (cVar1 == -1)) {
        if (uVar6 != 0) {
          if ((0x1f < local_10) || (local_10 < uVar6)) {
            FUN_0040b4f0(1);
            goto LAB_0041789c;
          }
          goto LAB_004178aa;
        }
        FUN_0040b4f0(1);
      }
      else if (uVar6 == 0) {
        *(char *)((int)local_18 + -1) = cVar1 + -1;
        FUN_0040b4f0(0);
      }
      else {
LAB_0041789c:
        FUN_0040b720(uVar6);
LAB_004178aa:
        puVar9 = &DAT_004e11e4;
        puVar12 = local_18;
        for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar12 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar12 = puVar12 + 1;
        }
        for (uVar5 = uVar6 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined1 *)puVar12 = *(undefined1 *)puVar9;
          puVar9 = (undefined4 *)((int)puVar9 + 1);
          puVar12 = (undefined4 *)((int)puVar12 + 1);
        }
        *(undefined1 *)((int)local_18 + uVar6) = 0;
        local_14 = uVar6;
      }
      uStack_4 = 0;
      piVar4 = (int *)FUN_0044a700(local_28);
      (**(code **)(*piVar4 + 0xc))(local_1c,0,0);
      uStack_4 = 0xffffffff;
      if (local_18 != (undefined4 *)0x0) {
        cVar1 = *(char *)((int)local_18 + -1);
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150((char *)((int)local_18 + -1));
        }
        else {
          *(char *)((int)local_18 + -1) = cVar1 + -1;
        }
      }
      local_18 = (undefined4 *)0x0;
      local_14 = 0;
      local_10 = 0;
      FUN_0044a6e0(local_28,iVar3);
      iVar8 = DAT_00508610;
      local_24[-0xd] = iVar3;
      uVar2 = DAT_0053beb8;
      if ((local_28 < iVar8) && (0x503f23 < (int)local_24)) {
        uVar2 = local_2c[0x16];
      }
      *local_24 = uVar2;
      FUN_004afce0(s_JABracer____d___char_id____d_004e11ec,local_28,uVar2);
      cVar1 = FUN_00417e90(local_28);
      piVar4 = &DAT_0053be28;
      if (cVar1 == '\0') {
        piVar4 = local_2c + 3;
      }
      *piVar4 = iVar3;
      local_2c[4] = 0;
      local_2c[5] = 0;
      FUN_004afce0(s_racer_car_added__object_nr_____d_004e120c,iVar3);
      local_28 = local_28 + 1;
      local_24 = local_24 + 0x47;
      local_2c = local_2c + 0x1c;
    } while (local_28 < DAT_00508610);
  }
  ExceptionList = local_c;
  return;
}

