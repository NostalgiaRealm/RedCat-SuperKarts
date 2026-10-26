/*
 * FUN_0049b190 at 0049b190
 * undefined FUN_0049b190(void)
 * Address ranges: 0049b190-0049b2fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0049b190(char *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  
  uVar5 = 0xffffffff;
  iVar6 = 0;
  pcVar7 = param_1;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  bVar3 = false;
  FUN_004afce0(s_Zoeken_naar___s_004fb960,param_1);
  if (0 < DAT_006a5e84) {
    iVar8 = 0;
    do {
      if (bVar3) {
        return iVar6;
      }
      if ((iVar8 < 0) || (DAT_006a5e84 <= iVar6)) {
        FUN_004afee0(s__s__d____T_ARRAY__get_used___ill_004e4300,
                     s_______Libs_Win3DLib_Include_arra_004fa4c0,0x43,iVar6,&DAT_006a5e94,
                     DAT_006a5e84,&DAT_006a5ead);
      }
      if (*(char *)(DAT_006a5e90 + iVar6) == '\0') {
LAB_0049b2c4:
        iVar6 = iVar6 + 1;
        iVar8 = iVar8 + 0x48;
      }
      else {
        FUN_004afce0(s_Compare__s_with_004fb950,param_1);
        puVar1 = (undefined4 *)(iVar8 + 0x14 + DAT_006a5e80);
        FUN_004afce0(&DAT_004fb948,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
        puVar1 = (undefined4 *)(iVar8 + 0x14 + DAT_006a5e80);
        if (*(int *)(iVar8 + 0x18 + DAT_006a5e80) == 0) {
          FUN_004afee0(s__s__d____string_is_not_initialis_004fb8fc,
                       s_______Libs_Win3DLib_Include_str__004fb924,0x24);
        }
        iVar4 = FUN_004cc8f0(param_1,*puVar1,~uVar5 - 5);
        if (iVar4 != 0) goto LAB_0049b2c4;
        bVar3 = true;
        puVar1 = (undefined4 *)(iVar8 + 0x14 + DAT_006a5e80);
        FUN_004afce0(s_Found__s_004fb8f0,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
      }
    } while (iVar6 < DAT_006a5e84);
    if (bVar3) {
      return iVar6;
    }
  }
  FUN_004afce0(s_Need_to_create_new_texture__s_004fb8d0,param_1);
  return -1;
}

