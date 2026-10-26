/*
 * FUN_004696d8 at 004696d8
 * undefined1 __register FUN_004696d8(void)
 * Address ranges: 004696d8-00469708;0046974d-004697b3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_004696d8(void)

{
  undefined1 uVar1;
  VARIANTARG *in_stack_00000004;
  int in_stack_0000000c;
  undefined1 local_10;
  undefined1 uStack_c;
  
  uStack_c = 0;
  local_10 = 0;
  FUN_004695f0();
  uVar1 = *(undefined1 *)(in_stack_0000000c + 4);
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch(uVar1) {
  case 2:
  case 3:
  case 0xb:
  case 0x10:
    uVar1 = local_10;
    break;
  case 4:
    break;
  case 5:
  case 7:
    break;
  case 6:
    break;
  case 8:
    if (*(BSTR *)&in_stack_00000004->n1 != (BSTR)0x0) {
      SysFreeString(*(BSTR *)&in_stack_00000004->n1);
    }
    *(undefined4 *)&in_stack_00000004->n1 = 0;
    uVar1 = local_10;
    break;
  case 9:
  case 0xd:
    if (*(int **)&in_stack_00000004->n1 != (int *)0x0) {
      (**(code **)(**(int **)&in_stack_00000004->n1 + 8))();
    }
    *(undefined4 *)&in_stack_00000004->n1 = 0;
    uVar1 = local_10;
    break;
  case 0xc:
    FUN_0040486c(in_stack_00000004);
    *(undefined4 *)&in_stack_00000004->n1 = 0;
    (in_stack_00000004->n1).decVal.Hi32 = 0;
    *(undefined4 *)((int)&in_stack_00000004->n1 + 8) = 0;
    *(undefined4 *)((int)&in_stack_00000004->n1 + 0xc) = 0;
    uVar1 = uStack_c;
  }
  return uVar1;
}

