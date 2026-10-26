/*
 * FUN_004b1f60 at 004b1f60
 * undefined FUN_004b1f60(void)
 * Address ranges: 004b1f60-004b20bc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004b1f60(byte *param_1,char *param_2)

{
  byte bVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  ushort local_ce;
  undefined4 local_cc;
  byte local_c8 [200];
  
  iVar5 = 0;
  iVar7 = 0;
  local_cc = DAT_004ffcb0;
  if (param_2 == (char *)0x0) {
    param_2 = (char *)&local_cc;
  }
  bVar1 = *param_1;
  if (bVar1 != 0) {
    pbVar6 = (byte *)&DAT_006a6510;
    do {
      local_ce = (ushort)bVar1;
      pcVar2 = _strstr(param_2,(char *)&local_ce);
      if (pcVar2 == (char *)0x0) {
        local_c8[iVar7] = *param_1;
        iVar7 = iVar7 + 1;
        if (0xc6 < iVar7) {
          FUN_004afee0(s__get_ini_arguments_online___s__d_004ffc10,
                       s_C__libraries_dxdraw_Inifile_cpp_004ffac0,0xf5,0xc6);
        }
      }
      else {
        uVar3 = 0xffffffff;
        local_c8[iVar7] = 0;
        pbVar8 = local_c8;
        do {
          pbVar9 = pbVar8;
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          pbVar9 = pbVar8 + 1;
          bVar1 = *pbVar8;
          pbVar8 = pbVar9;
        } while (bVar1 != 0);
        uVar3 = ~uVar3;
        pbVar8 = pbVar9 + -uVar3;
        pbVar9 = pbVar6;
        for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined4 *)pbVar9 = *(undefined4 *)pbVar8;
          pbVar8 = pbVar8 + 4;
          pbVar9 = pbVar9 + 4;
        }
        for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *pbVar9 = *pbVar8;
          pbVar8 = pbVar8 + 1;
          pbVar9 = pbVar9 + 1;
        }
        iVar5 = iVar5 + 1;
        if (0x6ab330 < (int)(pbVar6 + 200)) {
          FUN_004afee0(s__get_ini_arguments_online___s__d_004ffc64,
                       s_C__libraries_dxdraw_Inifile_cpp_004ffac0,0xe7,100);
        }
        iVar7 = 0;
        pbVar6 = pbVar6 + 200;
      }
      param_1 = param_1 + 1;
      bVar1 = *param_1;
    } while (bVar1 != 0);
  }
  local_c8[iVar7] = 0;
  uVar3 = 0xffffffff;
  pbVar6 = local_c8;
  do {
    pbVar8 = pbVar6;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pbVar8 = pbVar6 + 1;
    bVar1 = *pbVar6;
    pbVar6 = pbVar8;
  } while (bVar1 != 0);
  uVar3 = ~uVar3;
  pbVar6 = pbVar8 + -uVar3;
  pbVar8 = (byte *)(&DAT_006a6510 + iVar5 * 0x32);
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pbVar8 = *(undefined4 *)pbVar6;
    pbVar6 = pbVar6 + 4;
    pbVar8 = pbVar8 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pbVar8 = *pbVar6;
    pbVar6 = pbVar6 + 1;
    pbVar8 = pbVar8 + 1;
  }
  DAT_006ab460 = iVar5 + 1;
  return iVar5 + 1;
}

