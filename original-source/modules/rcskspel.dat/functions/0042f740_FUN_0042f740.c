/*
 * FUN_0042f740 at 0042f740
 * undefined FUN_0042f740(void)
 * Address ranges: 0042f740-0042f831
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042f740(int param_1)

{
  if (DAT_0053b9c0 != param_1) {
    DAT_0053b9c0 = param_1;
    switch(param_1) {
    case 0:
      _DAT_0053b9e4 = 0;
      DAT_0053b9e0 = 1;
      DAT_0053be54 = 1;
      FUN_0042f980();
      return;
    case 1:
      _DAT_0053b9e4 = 0;
      FUN_00420ba0(2,&LAB_00420fe0,&LAB_00420ff0,&DAT_00421000);
      return;
    case 2:
      _DAT_0053b9e4 = 0;
      return;
    case 3:
      _DAT_0053b9e4 = 1;
      FUN_00420ba0(4,FUN_0041fc60,FUN_0041fd90,FUN_0041fe50);
      return;
    case 4:
      DAT_0053b9e0 = 0;
      DAT_0053be54 = 0;
      DAT_0053b9bc = 0;
      return;
    case 6:
      _DAT_0053b9e4 = 1;
      FUN_00420ba0(0xc,FUN_00420730,FUN_00420850,FUN_00420950);
      return;
    case 8:
      _DAT_0053b9e4 = 1;
      FUN_00420ba0(0xb,FUN_0041fac0,&LAB_0041fb30,&LAB_0041fba0);
    }
  }
  return;
}

