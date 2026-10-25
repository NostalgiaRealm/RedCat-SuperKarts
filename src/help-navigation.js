/** Help-context numbers come from the original |CTXOMAP. String aliases are
 * retained for converted links, never guessed from displayed topic titles. */
export class HelpNavigation {
  constructor(data,context) {
    this.data=data;
    this.topics=new Map(data.topics.map(topic=>[topic.id,topic]));
    this.stack=[];this.history=[];
    this.visit(context??data.startTopic);
  }
  resolve(context) {
    const id=this.data.contextMap[String(context)]??context;
    return this.topics.get(id)??null;
  }
  get current(){return this.stack.at(-1);}
  get topic(){return this.topics.get(this.current.id);}
  get canBack(){return this.stack.length>1;}
  visit(context,{scrollTop=0,focus=null}={}) {
    const topic=this.resolve(context);
    if(!topic)return false;
    if(this.current){this.current.scrollTop=scrollTop;this.current.focus=focus;}
    this.stack.push({id:topic.id,scrollTop:0,focus:null});
    // Like WinHelp's history window, suppress consecutive duplicate entries.
    if(this.history[0]!==topic.id)this.history.unshift(topic.id);
    return true;
  }
  back(){if(!this.canBack)return false;this.stack.pop();return true;}
  contents(state){return this.visit(this.data.startTopic,state);}
}
