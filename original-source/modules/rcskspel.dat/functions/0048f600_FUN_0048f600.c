/*
 * FUN_0048f600 at 0048f600
 * undefined FUN_0048f600(void)
 * Address ranges: 0048f600-0048f777
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0048f600(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  int local_4;
  
  local_4 = 0;
  piVar3 = param_1;
  if (0 < param_1[100]) {
    do {
      if (*(int *)(DAT_006a5c38 + *piVar3 * 0xa9 + 0xa5) == 3) {
        iVar1 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0xe,1);
        if (iVar1 != 0) {
          uVar2 = FUN_004aaa00(iVar1);
          uVar5 = 0x4f;
          pcVar4 = s__s__d_____ZBUFFER__error_setting_004fa470;
          goto LAB_0048f68a;
        }
      }
      else {
        iVar1 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0xe,0);
        if (iVar1 != 0) {
          uVar2 = FUN_004aaa00(iVar1);
          uVar5 = 0x4b;
          pcVar4 = s__s__d_____ZBUFFER__error_setting_004e434c;
LAB_0048f68a:
          FUN_004afee0(pcVar4,s_D__work_rcsk_Code_Engine_Prog_ob_004fa444,uVar5,uVar2);
        }
      }
      (**(code **)(*DAT_006a621c + 0x5c))
                (DAT_006a621c,0x13,
                 *(undefined4 *)(&DAT_004fa400 + *(int *)(DAT_006a5c38 + *piVar3 * 0xa9 + 0xa5) * 8)
                );
      (**(code **)(*DAT_006a621c + 0x5c))
                (DAT_006a621c,0x14,
                 *(undefined4 *)(&DAT_004fa404 + *(int *)(DAT_006a5c38 + *piVar3 * 0xa9 + 0xa5) * 8)
                );
      if (*(char *)(DAT_006a5c38 + *piVar3 * 0xa9 + 0x90) != '\0') {
        FUN_004a0d80();
      }
      local_4 = local_4 + 1;
      piVar3 = piVar3 + 1;
    } while (local_4 < param_1[100]);
  }
  iVar1 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,0xe,1);
  if (iVar1 != 0) {
    uVar2 = FUN_004aaa00(iVar1);
    FUN_004afee0(s__s__d_____ZBUFFER__error_setting_004fa470,
                 s_D__work_rcsk_Code_Engine_Prog_ob_004fa444,0x5c,uVar2);
  }
  param_1[100] = 0;
  return;
}

