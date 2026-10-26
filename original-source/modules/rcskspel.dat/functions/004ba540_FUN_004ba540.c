/*
 * FUN_004ba540 at 004ba540
 * undefined FUN_004ba540(void)
 * Address ranges: 004ba540-004ba5df
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004ba540(void)

{
  undefined4 uVar1;
  undefined1 local_4 [4];
  
  if (DAT_006ab95c == 0) {
    FUN_004afee0(s__s__d_____handle_mouse__Mouse_is_00502028,
                 s_C__libraries_dxdraw_Mouse_cpp_00501cc8,0x304);
  }
  FUN_004b9ea0(&DAT_006ab954,&DAT_006ab958,local_4);
  if ((DAT_006ab960 != 0) && (DAT_006ab968 != 0)) {
    if (DAT_00501c90 == 1) {
      SetCursor(DAT_006ab97c);
    }
    else if ((DAT_00501c90 == 2) &&
            ((DAT_00501c6c != DAT_006ab954 || (DAT_00501c70 != DAT_006ab958)))) {
      uVar1 = FUN_004bb9e0();
      FUN_004ba400(uVar1);
      uVar1 = FUN_004bb9e0();
      FUN_004ba490(uVar1);
      return 0;
    }
  }
  return 0;
}

