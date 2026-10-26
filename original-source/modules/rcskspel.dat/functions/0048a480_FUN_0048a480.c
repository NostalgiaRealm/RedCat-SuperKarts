/*
 * FUN_0048a480 at 0048a480
 * undefined FUN_0048a480(void)
 * Address ranges: 0048a480-0048a4e3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0048a480(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d150d;
  local_c = ExceptionList;
  if (DAT_0067da6c == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x10);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      DAT_0067da6c = 0;
    }
    else {
      DAT_0067da6c = FUN_0048a430(pvVar1);
    }
    FUN_0048a470();
  }
  ExceptionList = local_c;
  return DAT_0067da6c;
}

