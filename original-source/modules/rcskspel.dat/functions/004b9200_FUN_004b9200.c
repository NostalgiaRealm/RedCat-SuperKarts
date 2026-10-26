/*
 * FUN_004b9200 at 004b9200
 * undefined FUN_004b9200(void)
 * Address ranges: 004b9200-004b9254
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b9200(void)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_004afce0(s_getting_screen_mode_info_00501794);
  iVar1 = (**(code **)(*DAT_006a649c + 0x20))(DAT_006a649c,0,0,0,&LAB_004b91b0);
  if (iVar1 != 0) {
    uVar2 = FUN_004b0190(iVar1);
    FUN_004afee0(s__s__d____could_not_get_mode_info_00501764,
                 s_C__libraries_dxdraw_Hwinfo_cpp_0050137c,0x1d6,uVar2);
  }
  FUN_004afce0(s_done_getting_screen_mode_info_00501744);
  return 0;
}

