/*
 * FUN_004b2680 at 004b2680
 * undefined FUN_004b2680(void)
 * Address ranges: 004b2680-004b27e3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b2680(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  
  FUN_004b9570(param_1,0xfffffd00,2);
  FUN_004bf930(param_2,0x300,1,param_1);
  if ((*(byte *)(param_1 + 0xc) & 0x20) != 0) {
    FUN_004afee0(s__s__d____error_reading_004ffee4,s_C__libraries_dxdraw_Rcpcx_cpp_004fff00,0x124);
  }
  pcVar3 = param_2 + 2;
  iVar1 = 0;
  pcVar6 = param_2;
  pcVar5 = param_2;
  pcVar4 = param_2;
  do {
    *(char *)(DAT_006ab468 + iVar1 * 4) = pcVar3[-2];
    *(char *)(DAT_006ab468 + 1 + iVar1 * 4) = pcVar3[-1];
    *(char *)(DAT_006ab468 + 2 + iVar1 * 4) = *pcVar3;
    if (iVar1 == DAT_004ffedc) {
      pcVar3[-2] = DAT_006ab774;
      *(char *)(DAT_006ab468 + iVar1 * 4) = DAT_006ab774;
      pcVar3[-1] = DAT_006ab778;
      *(char *)(DAT_006ab468 + 1 + iVar1 * 4) = DAT_006ab778;
      *pcVar3 = DAT_006ab77c;
      *(char *)(DAT_006ab468 + 2 + iVar1 * 4) = DAT_006ab77c;
      pcVar4 = (char *)(uint)*(byte *)(DAT_006ab468 + iVar1 * 4);
      pcVar5 = (char *)(uint)*(byte *)(DAT_006ab468 + 1 + iVar1 * 4);
      pcVar6 = (char *)(uint)*(byte *)(DAT_006ab468 + 2 + iVar1 * 4);
    }
    iVar1 = iVar1 + 1;
    pcVar3 = pcVar3 + 3;
  } while (iVar1 < 0x100);
  if (DAT_004ffee0 != 0) {
    iVar2 = 0;
    iVar1 = DAT_006ab468;
    do {
      if ((((iVar2 != DAT_004ffedc) && (pcVar4 == (char *)(uint)*(byte *)(iVar1 + iVar2 * 4))) &&
          (pcVar5 == (char *)(uint)*(byte *)(iVar1 + 1 + iVar2 * 4))) &&
         (pcVar6 == (char *)(uint)*(byte *)(iVar1 + 2 + iVar2 * 4))) {
        *(char *)(iVar1 + iVar2 * 4) = DAT_006ab774 + '\x01';
        *param_2 = DAT_006ab774 + '\x01';
        iVar1 = DAT_006ab468;
      }
      iVar2 = iVar2 + 1;
      param_2 = param_2 + 3;
    } while (iVar2 < 0x100);
  }
  return 0;
}

