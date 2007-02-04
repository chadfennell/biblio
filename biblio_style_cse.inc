<?php
// $Id$
function biblio_style_cse_info(){

    return array('cse'=>'Council of Science Editors (CSE)');
                 
}
function biblio_style_cse($pub){

  if (variable_get('biblio_normalize', 0)) {
    $authors = _biblio_parse_authors(check_plain($pub->biblio_authors));
  } else {
    $authors = check_plain($pub->biblio_authors);
  } 
  $output .= '<span class="biblio-authors">' . str_replace(";", ",", str_replace(array(".",","),"",_biblio_author_links($authors))) . "</span>.&nbsp; \n";
//  $output .= (strrpos($authors, '.' ) == strlen($authors))? ".&nbsp;&nbsp;":" ";

      switch ($pub->biblio_type) {
        case 1: // Journal Article
        case 2: //Conference Paper
        case 3: // are all
        case 4: 
        case 5: 
        case 6:
        case 7:
        case 8: 
        case 9:
        default:
          if (isset($pub->biblio_year)) {
            if ($pub->biblio_year == 0) { $pub->biblio_year = t("In Press"); }
            $output .= check_plain($pub->biblio_year).".&nbsp;&nbsp;" ;
            
          }
          $output .= '<span class="biblio-title">' . l("$pub->title", "node/$pub->nid") . ". </span> \n";
          $output .= ($pub->biblio_secondary_title) ? check_plain($pub->biblio_secondary_title).'. ' : '';
          $output .= ($pub->biblio_volume)?  check_plain($pub->biblio_volume) : '';
          $output .= ($pub->biblio_issue) ? '(' . check_plain($pub->biblio_issue).')' :'';
          $output .= ($pub->biblio_pages) ? ':' . str_replace(" ","",check_plain($pub->biblio_pages)).'.' :'';
          break; // generic
      } 

/*  if ($pub->biblio_date) $output .= ', ' . check_plain($pub->biblio_date);
  if ($pub->biblio_number) $output .= ', Number ' . check_plain($pub->biblio_number);

  if ($pub->biblio_place_published) $output .= ', ' . check_plain($pub->biblio_place_published);
*/
  return $output;

}
?>