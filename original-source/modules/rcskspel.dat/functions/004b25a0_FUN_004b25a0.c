/*
 * FUN_004b25a0 at 004b25a0
 * undefined FUN_004b25a0(void)
 * Address ranges: 004b25a0-004b2674
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b25a0(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 local_300;
  undefined1 local_2ff [767];
  
  iVar1 = FUN_004b96d0(param_1);
  if (iVar1 == 0) {
    return 1000;
  }
  FUN_004b9570(iVar1,0xfffffd00,2);
  FUN_004bf930(&local_300,0x300,1,iVar1);
  if ((*(byte *)(iVar1 + 0xc) & 0x20) != 0) {
    FUN_004afee0(s__s__d____error_reading_004ffee4,s_C__libraries_dxdraw_Rcpcx_cpp_004fff00,0x109);
  }
  iVar2 = 0;
  puVar3 = local_2ff;
  do {
    *(undefined1 *)(iVar2 + DAT_006ab468) = puVar3[-1];
    *(undefined1 *)(iVar2 + 1 + DAT_006ab468) = *puVar3;
    *(undefined1 *)(iVar2 + 2 + DAT_006ab468) = puVar3[1];
    iVar2 = iVar2 + 4;
    puVar3 = puVar3 + 3;
  } while (iVar2 < 0x400);
  if (param_2 != 0) {
    FUN_004b2340(DAT_006ab468,0,0x100);
  }
  FUN_004b9840(iVar1);
  return 0;
}

