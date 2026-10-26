/*
 * FUN_0042df90 at 0042df90
 * undefined FUN_0042df90(void)
 * Address ranges: 0042df90-0042e90e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042df90(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 local_f4;
  undefined1 local_f0 [4];
  undefined1 *local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  int local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  int local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  int local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  int local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  int local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined1 local_80 [36];
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [32];
  undefined1 local_20 [20];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd0ce;
  local_c = ExceptionList;
  iVar8 = 0;
  ExceptionList = &local_c;
  if (DAT_00508610 != -1 && -1 < DAT_00508610 + 1) {
    do {
      FUN_004be8cb(local_20,0x13,s_SSR_d_004eab18,iVar8);
      uVar2 = FUN_004a5410(local_20,4);
      (&DAT_004e0298)[iVar8 * 0x4b] = uVar2;
      FUN_00475360();
      FUN_0044a700(iVar8);
      uVar3 = FUN_0044cf60();
      iVar4 = FUN_00476580(uVar3);
      FUN_0042eab0(iVar4);
      local_4 = 0;
      FUN_0042eab0(iVar4 + 0x10);
      local_4 = 1;
      iVar4 = FUN_00476510(DAT_0053be2c);
      FUN_0042eab0(iVar4);
      local_4._0_1_ = 2;
      FUN_0042eab0(iVar4 + 0x10);
      local_4._0_1_ = 3;
      FUN_0042eab0(iVar4 + 0x20);
      local_4._0_1_ = 4;
      FUN_0042eab0(iVar4 + 0x30);
      local_4._0_1_ = 5;
      FUN_0042eab0(iVar4 + 0x40);
      local_4._0_1_ = 6;
      FUN_0042ebd0(iVar4 + 0x50);
      local_4._0_1_ = 7;
      FUN_0044a700(iVar8);
      uVar3 = FUN_0044cf60();
      FUN_004765d0(local_f0,DAT_0053be2c,uVar3);
      local_4 = CONCAT31(local_4._1_3_,8);
      _DAT_0053bedc = FUN_004a6200(local_20);
      puVar6 = &DAT_004d2404;
      if (local_ec != (undefined1 *)0x0) {
        puVar6 = local_ec;
      }
      iVar4 = FUN_00475110();
      puVar5 = *(undefined1 **)(iVar4 + 4);
      if (puVar5 == (undefined1 *)0x0) {
        puVar5 = &DAT_004d2404;
      }
      FUN_004afce0(s____player___d__ssr_anim__d_mesh___004eab20,iVar8,uVar2,puVar5,puVar6);
      iVar4 = FUN_00475110();
      puVar6 = *(undefined1 **)(iVar4 + 4);
      if (puVar6 == (undefined1 *)0x0) {
        puVar6 = &DAT_004d2404;
      }
      FUN_004be8cb(local_80,0x1d,&DAT_004eab50,puVar6);
      puVar6 = local_ec;
      if (local_ec == (undefined1 *)0x0) {
        puVar6 = &DAT_004d2404;
      }
      FUN_004be8cb(local_40,0x1d,&DAT_004eab54,puVar6);
      FUN_004a5c00(uVar2,local_80,local_40);
      uVar3 = FUN_004a3040(local_40);
      if (iVar8 == 0) {
        iVar4 = FUN_004a6200(s_racer_5_004eab58);
        local_f4 = *(undefined4 *)
                    (*(int *)(*(int *)(iVar4 * 9 + 4 + DAT_006a5f78) + 4) * 0x10 + 4 + DAT_006a5f30)
        ;
      }
      uVar7 = FUN_004a74b0(local_80);
      if (iVar8 == DAT_00508610) {
        *(undefined4 *)
         (DAT_006a5c38 + *(int *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + 0x95) = uVar3;
        iVar4 = *(int *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20);
      }
      else {
        cVar1 = FUN_00417e90(iVar8);
        iVar4 = DAT_0053be28;
        if (cVar1 == '\0') {
          iVar4 = (&DAT_005081bc)[iVar8 * 0x1c];
        }
        *(undefined4 *)(DAT_006a5c38 + *(int *)(iVar4 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + 0x95) =
             uVar3;
        cVar1 = FUN_00417e90(iVar8);
        iVar4 = DAT_0053be28;
        if (cVar1 == '\0') {
          iVar4 = (&DAT_005081bc)[iVar8 * 0x1c];
        }
        iVar4 = *(int *)(iVar4 * 0xd0 + 0xc + DAT_0067ee20);
      }
      *(undefined4 *)(DAT_006a5c38 + iVar4 * 0xa9 + 0x99) = uVar7;
      FUN_004ad120(&DAT_0053a5b4);
      iVar4 = FUN_00475120();
      puVar6 = *(undefined1 **)(iVar4 + 4);
      if (puVar6 == (undefined1 *)0x0) {
        puVar6 = &DAT_004d2404;
      }
      FUN_004be8cb(local_80,0x1d,&DAT_004eab60,puVar6);
      FUN_004a5800(uVar2,local_80,local_40);
      FUN_004a74b0(local_80);
      iVar4 = FUN_00475120();
      puVar6 = *(undefined1 **)(iVar4 + 4);
      if (puVar6 == (undefined1 *)0x0) {
        puVar6 = &DAT_004d2404;
      }
      FUN_004afce0(s_wheel_forward__s_004eab64,puVar6);
      iVar4 = FUN_00475130();
      puVar6 = *(undefined1 **)(iVar4 + 4);
      if (puVar6 == (undefined1 *)0x0) {
        puVar6 = &DAT_004d2404;
      }
      FUN_004be8cb(local_80,0x1d,&DAT_004eab78,puVar6);
      FUN_004a5800(uVar2,local_80,local_40);
      FUN_004a74b0(local_80);
      iVar4 = FUN_00475130();
      puVar6 = *(undefined1 **)(iVar4 + 4);
      if (puVar6 == (undefined1 *)0x0) {
        puVar6 = &DAT_004d2404;
      }
      FUN_004afce0(s_wheel_back__s_004eab7c,puVar6);
      FUN_004a5800(uVar2,local_80,local_40);
      if (iVar8 == DAT_00508610) {
        iVar4 = FUN_004906b0(0);
        *(undefined4 *)(DAT_006a5c38 + iVar4 * 0xa9 + 0x95) = local_f4;
        iVar4 = FUN_004906b0(1);
        *(undefined4 *)(DAT_006a5c38 + iVar4 * 0xa9 + 0x95) = local_f4;
        iVar4 = FUN_004906b0(2);
        *(undefined4 *)(DAT_006a5c38 + iVar4 * 0xa9 + 0x95) = local_f4;
        iVar4 = FUN_004906b0(3);
        *(undefined4 *)(DAT_006a5c38 + iVar4 * 0xa9 + 0x95) = local_f4;
      }
      else {
        FUN_00417e90(iVar8);
        iVar4 = FUN_004906b0(0);
        *(undefined4 *)(DAT_006a5c38 + iVar4 * 0xa9 + 0x95) = local_f4;
        FUN_00417e90(iVar8);
        iVar4 = FUN_004906b0(1);
        *(undefined4 *)(DAT_006a5c38 + iVar4 * 0xa9 + 0x95) = local_f4;
        FUN_00417e90(iVar8);
        iVar4 = FUN_004906b0(2);
        *(undefined4 *)(DAT_006a5c38 + iVar4 * 0xa9 + 0x95) = local_f4;
        FUN_00417e90(iVar8);
        iVar4 = FUN_004906b0(3);
        *(undefined4 *)(DAT_006a5c38 + iVar4 * 0xa9 + 0x95) = local_f4;
        FUN_00417e90(iVar8);
      }
      iVar4 = FUN_004906b0(4);
      *(undefined4 *)(DAT_006a5c38 + iVar4 * 0xa9) = 2;
      if (local_ec != (undefined1 *)0x0) {
        cVar1 = local_ec[-1];
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150(local_ec + -1);
        }
        else {
          local_ec[-1] = cVar1 + -1;
        }
      }
      local_ec = (undefined1 *)0x0;
      local_e8 = 0;
      local_e4 = 0;
      FUN_004bc150(local_8c);
      local_8c = 0;
      local_88 = 0;
      local_84 = 0;
      if (local_9c != 0) {
        cVar1 = *(char *)(local_9c + -1);
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150((char *)(local_9c + -1));
        }
        else {
          *(char *)(local_9c + -1) = cVar1 + -1;
        }
      }
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      if (local_ac != 0) {
        cVar1 = *(char *)(local_ac + -1);
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150((char *)(local_ac + -1));
        }
        else {
          *(char *)(local_ac + -1) = cVar1 + -1;
        }
      }
      local_ac = 0;
      local_a8 = 0;
      local_a4 = 0;
      if (local_bc != 0) {
        cVar1 = *(char *)(local_bc + -1);
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150((char *)(local_bc + -1));
        }
        else {
          *(char *)(local_bc + -1) = cVar1 + -1;
        }
      }
      local_bc = 0;
      local_b8 = 0;
      local_b4 = 0;
      if (local_cc != 0) {
        cVar1 = *(char *)(local_cc + -1);
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150((char *)(local_cc + -1));
        }
        else {
          *(char *)(local_cc + -1) = cVar1 + -1;
        }
      }
      local_cc = 0;
      local_c8 = 0;
      local_c4 = 0;
      if (local_dc != 0) {
        cVar1 = *(char *)(local_dc + -1);
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150((char *)(local_dc + -1));
        }
        else {
          *(char *)(local_dc + -1) = cVar1 + -1;
        }
      }
      local_dc = 0;
      local_d8 = 0;
      local_d4 = 0;
      local_4 = 0xffffffff;
      if (local_4c != 0) {
        cVar1 = *(char *)(local_4c + -1);
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150((char *)(local_4c + -1));
        }
        else {
          *(char *)(local_4c + -1) = cVar1 + -1;
        }
      }
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      if (local_5c != 0) {
        cVar1 = *(char *)(local_5c + -1);
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150(local_5c + -1);
        }
        else {
          *(char *)(local_5c + -1) = cVar1 + -1;
        }
      }
      iVar8 = iVar8 + 1;
      local_5c = 0;
      local_58 = 0;
      local_54 = 0;
    } while (iVar8 < DAT_00508610 + 1);
  }
  ExceptionList = local_c;
  return;
}

