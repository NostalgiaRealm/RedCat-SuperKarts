import {HelpNavigation} from './help-navigation.js';

/** Browser window controls around unmodified original Help topic content. */
export class HelpViewer {
  constructor(data,context,{screen,button,onClose}) {
    this.data=data;this.screen=screen;this.button=button;this.onClose=onClose;
    this.navigation=new HelpNavigation(data,context);
    if(!this.navigation.current)throw new Error('Original Help context not found');
    this.panel=null;
    this.render();
  }
  state(){
    const links=[...this.article.querySelectorAll('[data-help-topic]')];
    const focus=links.indexOf(document.activeElement);
    return {scrollTop:this.screen.scrollTop,focus:focus>=0?focus:null};
  }
  visit(context){
    if(!this.navigation.visit(context,this.state()))return;
    this.panel=null;this.render();
  }
  back(){
    if(!this.navigation.back())return;
    this.panel=null;this.render(true);
  }
  closePanel(){
    if(!this.panel)return false;
    const control=this.panel;this.panel=null;this.render(false,true);
    this.root.querySelector(`[data-help-action="${control}"]`)?.focus({preventScroll:true});
    return true;
  }
  render(restore=false,retainScroll=false){
    const {data,navigation,button,screen}=this,topic=navigation.topic;
    const scroll=retainScroll?screen.scrollTop:restore?navigation.current.scrollTop:0;
    const root=document.createElement('div');root.className='help-window';this.root=root;
    const header=document.createElement('header'),title=document.createElement('h1');
    title.textContent=data.title;header.append(title,button('Terug',this.onClose));
    const toolbar=document.createElement('div');toolbar.className='help-toolbar';toolbar.setAttribute('role','toolbar');toolbar.setAttribute('aria-label','Helpnavigatie');
    const control=(label,action,handler)=>{
      const item=button(label,handler);item.dataset.helpAction=action;toolbar.append(item);return item;
    };
    control('Inhoud','contents',()=>this.visit(data.startTopic));
    control('Vorige','back',()=>this.back()).disabled=!navigation.canBack;
    for(const [label,panel]of [['Index','index'],['Geschiedenis','history']]){
      const item=control(label,panel,()=>{
        this.panel=this.panel===panel?null:panel;this.render(false,true);
        (this.root.querySelector('.help-navigation-panel input')
          ??this.root.querySelector(`[data-help-action="${panel}"]`))?.focus({preventScroll:true});
      });
      item.setAttribute('aria-expanded',String(this.panel===panel));
    }
    root.append(header,toolbar);
    const nav=document.createElement('nav');nav.setAttribute('aria-label',data.title);
    const topicLink=item=>{
      const link=document.createElement('a');link.href='#help-'+encodeURIComponent(item.id);
      link.dataset.helpTopic=item.id;link.dataset.helpContext=item.contextId;link.textContent=item.title;
      if(item.id===topic.id)link.setAttribute('aria-current','page');return link;
    };
    for(const item of data.topics)nav.append(topicLink(item));
    root.append(nav);
    if(this.panel){
      const panel=document.createElement('section');panel.className='help-navigation-panel';panel.dataset.helpPanel=this.panel;
      const heading=document.createElement('h2');heading.textContent=this.panel==='index'?'Index':'Geschiedenis';panel.append(heading);
      if(this.panel==='history'){
        const list=document.createElement('ol');
        for(const id of navigation.history){const row=document.createElement('li');row.append(topicLink(navigation.topics.get(id)));list.append(row);}
        panel.append(list);
      }else{
        const label=document.createElement('label');label.textContent='Trefwoord: ';
        const input=document.createElement('input');input.type='search';input.setAttribute('aria-label','Trefwoord');label.append(input);panel.append(label);
        // InputController leaves edit fields to their own keyboard handling.
        input.onkeydown=event=>{
          if(event.code==='Escape'){event.preventDefault();event.stopPropagation();this.closePanel();}
        };
        const list=document.createElement('ul');panel.append(list);
        const update=()=>{
          list.replaceChildren();
          for(const keyword of data.keywordIndex??[]){
            if(!keyword.keyword.toLocaleLowerCase('nl').includes(input.value.toLocaleLowerCase('nl')))continue;
            const row=document.createElement('li'),name=document.createElement('span');name.textContent=keyword.keyword+': ';row.append(name);
            for(const [index,context]of keyword.contextIds.entries()){
              const item=navigation.resolve(context);if(!item)continue;
              if(index)row.append(' · ');row.append(topicLink(item));
            }
            list.append(row);
          }
        };
        input.oninput=update;update();
      }
      root.append(panel);
    }
    const article=document.createElement('article');article.className='original-help';article.dataset.topic=topic.id;article.tabIndex=-1;
    // Only the allowlisted converter's original topic HTML reaches this node.
    // HLP macros and external commands are never evaluated.
    article.innerHTML=topic.html;root.append(article);this.article=article;
    root.onclick=event=>{
      const link=event.target.closest('[data-help-topic]');
      if(link){event.preventDefault();this.visit(link.dataset.helpContext??link.dataset.helpTopic);}
    };
    screen.replaceChildren(root);screen.scrollTop=scroll;
    if(restore&&navigation.current.focus!==null)
      article.querySelectorAll('[data-help-topic]')[navigation.current.focus]?.focus({preventScroll:true});
    else if(!retainScroll)article.focus({preventScroll:true});
  }
}
