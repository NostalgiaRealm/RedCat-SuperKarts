/*
 * FUN_0049b350 at 0049b350
 * undefined FUN_0049b350(void)
 * Address ranges: 0049b350-0049b574
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0049b350(char *param_1,undefined4 param_2,char *param_3,char *param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  char *pcVar8;
  char *pcVar9;
  int local_190;
  undefined1 local_188 [8];
  char local_180;
  undefined4 uStack_17f;
  undefined1 local_100 [256];
  
  local_190 = 0;
  FUN_004b1d60(param_2);
  iVar2 = FUN_004b1ed0(s_objects_004fba14,s_count_004fba1c);
  FUN_004afce0(s_Anim_to_find___s_004fba00,param_1);
  do {
    if (iVar2 <= local_190) {
      return 1;
    }
    FUN_004bea92(local_188,&DAT_004fb9fc,local_190);
    FUN_004b1f10(s_objects_004fba14,local_188,local_100,0x100);
    iVar3 = FUN_004b1f60(local_100,&DAT_004fb9f8);
    if (iVar3 < 6) {
      FUN_004afee0(s___s___d__Illegal_entry_in__s__d_f_004fb9a4,
                   s_D__work_rcsk_Code_Engine_Prog_ob_004fb9cc,0x135,param_2,local_190);
    }
    FUN_004b2110(4,&local_180,0x80);
    if (local_180 == ' ') {
      puVar7 = &uStack_17f;
      pcVar8 = &local_180;
      for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined4 *)pcVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        pcVar8 = pcVar8 + 4;
      }
      *(undefined2 *)pcVar8 = *(undefined2 *)puVar7;
      pcVar8[2] = *(char *)((int)puVar7 + 2);
    }
    FUN_004afce0(s_Name___s_004fb998,&local_180);
    iVar3 = __strcmpi(&local_180,param_1);
    if (iVar3 == 0) {
      FUN_004b2110(0,&local_180,0x80);
      uVar4 = 0xffffffff;
      pcVar8 = &local_180;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      iVar3 = ~uVar4 - 1;
      if (iVar3 < 0) {
LAB_0049b4a8:
        iVar3 = 0;
      }
      else {
        do {
          if ((&local_180)[iVar3] == '\\') {
            if (iVar3 < 0) goto LAB_0049b4a8;
            iVar3 = iVar3 + 1;
            goto LAB_0049b4ad;
          }
          iVar3 = iVar3 + -1;
        } while (-1 < iVar3);
        iVar3 = 0;
      }
LAB_0049b4ad:
      pcVar8 = param_3;
      for (iVar5 = 0x20; iVar5 != 0; iVar5 = iVar5 + -1) {
        pcVar8[0] = '\0';
        pcVar8[1] = '\0';
        pcVar8[2] = '\0';
        pcVar8[3] = '\0';
        pcVar8 = pcVar8 + 4;
      }
      uVar4 = 0xffffffff;
      pcVar8 = &local_180 + iVar3;
      do {
        pcVar9 = pcVar8;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar9 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar9;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      pcVar8 = pcVar9 + -uVar4;
      pcVar9 = param_3;
      for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar9 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
      }
      FUN_004afce0(s_Found_mesh___s_004fb988,param_3);
      FUN_004b2110(1,&local_180,0x80);
      uVar4 = 0xffffffff;
      pcVar8 = &local_180;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      iVar3 = ~uVar4 - 1;
      if (iVar3 < 0) {
LAB_0049b51a:
        iVar3 = 0;
      }
      else {
        do {
          if ((&local_180)[iVar3] == '\\') {
            if (iVar3 < 0) goto LAB_0049b51a;
            iVar3 = iVar3 + 1;
            goto LAB_0049b51f;
          }
          iVar3 = iVar3 + -1;
        } while (-1 < iVar3);
        iVar3 = 0;
      }
LAB_0049b51f:
      pcVar8 = param_4;
      for (iVar5 = 0x20; iVar5 != 0; iVar5 = iVar5 + -1) {
        pcVar8[0] = '\0';
        pcVar8[1] = '\0';
        pcVar8[2] = '\0';
        pcVar8[3] = '\0';
        pcVar8 = pcVar8 + 4;
      }
      uVar4 = 0xffffffff;
      pcVar8 = &local_180 + iVar3;
      do {
        pcVar9 = pcVar8;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar9 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar9;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      pcVar8 = pcVar9 + -uVar4;
      pcVar9 = param_4;
      for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar9 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
      }
      FUN_004afce0(s_Found_texture___s_004fb974,param_4);
    }
    local_190 = local_190 + 1;
  } while( true );
}

