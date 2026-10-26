/*
 * FUN_00479fa8 at 00479fa8
 * undefined __register FUN_00479fa8(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00479fa8-0047a064
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00479fa8(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined2 extraout_var_05;
  undefined2 extraout_var_06;
  undefined2 extraout_var_07;
  undefined2 extraout_var_08;
  undefined2 extraout_var_09;
  undefined2 extraout_var_10;
  undefined2 extraout_var_11;
  undefined2 extraout_var_12;
  
  bVar1 = FUN_0044f288(CONCAT22((short)((uint)param_1 >> 0x10),0x280),
                       CONCAT22((short)((uint)param_2 >> 0x10),0x1e0),0x18);
  if (!bVar1) {
    bVar1 = FUN_0044f288(CONCAT22(extraout_var,0x280),CONCAT22(extraout_var_06,0x1e0),0x10);
    if (!bVar1) {
      bVar1 = FUN_0044f288(CONCAT22(extraout_var_00,0x280),CONCAT22(extraout_var_07,0x1e0),0xf);
      if (!bVar1) {
        bVar1 = FUN_0044f288(CONCAT22(extraout_var_01,0x280),CONCAT22(extraout_var_08,0x1e0),0x20);
        if (!bVar1) {
          bVar1 = FUN_0044f288(CONCAT22(extraout_var_02,800),CONCAT22(extraout_var_09,600),0x18);
          if (!bVar1) {
            bVar1 = FUN_0044f288(CONCAT22(extraout_var_03,800),CONCAT22(extraout_var_10,600),0x10);
            if (!bVar1) {
              bVar1 = FUN_0044f288(CONCAT22(extraout_var_04,800),CONCAT22(extraout_var_11,600),0xf);
              if (!bVar1) {
                bVar1 = FUN_0044f288(CONCAT22(extraout_var_05,800),CONCAT22(extraout_var_12,600),
                                     0x20);
                if (!bVar1) {
                  *(undefined4 *)(*(int *)PTR_DAT_0047c86c + 0x68) = 0;
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}

