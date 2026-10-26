/*
 * FUN_004ae4a0 at 004ae4a0
 * undefined FUN_004ae4a0(void)
 * Address ranges: 004ae4a0-004ae53f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004ae4a0(void)

{
  int iVar1;
  
  iVar1 = DAT_006a63de;
  if (DAT_006a6394 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                 &DAT_006a639c,DAT_006a638c,&DAT_006a63b5);
  }
  if ((iVar1 < 0) || (DAT_006a638c <= iVar1)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                 &DAT_006a639c,iVar1,DAT_006a638c);
  }
  if (*(char *)(DAT_006a6398 + iVar1) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                 &DAT_006a639c,iVar1);
  }
  return iVar1 * 0xb0 + 0x48 + DAT_006a6388;
}

